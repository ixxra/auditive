/*

This file is part of Auditive.

Copyright 2010-2012 Graeme Sheppard.

Auditive is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Auditive is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Auditive. If not, see <http://www.gnu.org/licenses/>.

*/

using Gst;

// these below attempt to correct Vala shortcomings
delegate void foreach_delegate (Gst.TagList list, string tag);
//extern void taglist_foreach_job (Gst.TagList list, foreach_delegate func, void* user_data); //gstreamer-1.0: This is no longer needed to compile
extern bool check_tag_exists (void* list, char* tag);

public const int64 nsec = 1000000000;


string time_text (int64 num)
{
  int64 total = num / nsec;
  return "%d:%02d".printf ((int) total / 60, (int) total % 60);
}


class auditive
{
  public world_wide *world;
  MainLoop loop = new MainLoop (null, false);
  dynamic Element play;
  Gst.Bus bus;
  int64 resume_position = 0;
  string song_label;
  string song_title;
  string song_artist;
  string song_album;
  string song_short_file_name;
  int screen_size = 0;
  int auto_start_number = -1;
  string auto_start_name = "";

  public auditive()
  {
    world = new world_wide();
    world->player = this;
    world->debug = new dbg (world);
    world->ext_screen = new external (world);
    world->help_screen = new help (world);
    world->playing_state = world_wide.playing_type.stop;
    world->files_array = new GLib.List <files*>();
    config_setup (world);
  }

  public void set_playing (string source)
  {
    stop();
    song_label = "";
    song_short_file_name = get_file_from_path (source);
    element_make();
    play.uri = "file://" + source;
    bus = play.get_bus();
    bus.add_watch (GLib.Priority.DEFAULT, bus_callback);
    playing();
    world->debug->add ("play " + song_short_file_name);
    world->debug->add ("from " + get_base_from_path (source));
  }

  public void stop()
  {
    if (world->playing_screen != null)
     world->playing_screen->reset_stop(); // note to set play marker after stop
    play.set_state (State.NULL);
    song_label = song_title = song_artist = song_album = "";
    if (world->playing_state != world_wide.playing_type.stop)
      world->debug->add ("stop");
    world->playing_state = world_wide.playing_type.stop;
  }

  public void advance_song()
  {
    if (world->playing_screen == null)
      stop();
    else
      world->playing_screen->advance_song(); // whether playlist or filelist
    draw();
  }

  void element_make()
  {
    play = ElementFactory.make ("playbin", "play");
  }

  public int64 get_position()
  {
    int64 position;
    var fmt = Gst.Format.TIME;
    play.query_position (fmt, out position);
    return position;
  }

  public int64 get_duration()
  {
    int64 duration;
    var fmt = Gst.Format.TIME;
    play.query_duration (fmt, out duration);
    return duration;
  }

  public void set_position (int64 position)
  {
    play.seek_simple (Gst.Format.TIME, Gst.SeekFlags.FLUSH | Gst.SeekFlags.KEY_UNIT, position);
  }
      
  public void pause()
  {
    play.set_state (State.PAUSED);
    world->playing_state = world_wide.playing_type.pause;
  }

  public void playing()
  {
    play.set_state (State.PLAYING);
    world->playing_state = world_wide.playing_type.play;
  }

  public void adjust_position (int signed_seconds)
  {
    int64 new_position = get_position() + signed_seconds * nsec;
    if (new_position < 0 || new_position >= get_duration())
      return;
    set_position (new_position);
  }

  public void adjust_position_fraction (int signed_decivar)
  {
    int64 adjust = get_duration() / (nsec * 10);
    if (adjust > 123000456) // close to four years
      return; // overflow
    adjust_position ((int) adjust * signed_decivar);
  }

  public screen* index_screen (world_wide.screen_type screen_type = world->screen_current)
  {
    switch (screen_type)
    {
      case world_wide.screen_type.file_list:
        return (screen*) world->files_array.nth_data (world->screen_files);
          
      case world_wide.screen_type.view_list:
        return (screen*) world->view_screen;

      case world_wide.screen_type.play_list:
        return (screen*) world->play_screen;

      case world_wide.screen_type.ext_list:
        return (screen*) world->ext_screen;

      case world_wide.screen_type.debug:
        return (screen*) world->debug;

      case world_wide.screen_type.help:
        return (screen*) world->help_screen;
      
      default:
        world->debug->alert ("Undetermined screen");
        return (screen*) world->debug;
    }
  }

  public void remember_screen (world_wide.screen_type screen_type)
  {
    index_screen (screen_type)->last_screen = world->screen_current;
    world->screen_current = screen_type;
    if (screen_type == world_wide.screen_type.debug)
      world->debug->zoom_to_last_line();
    draw();
  }
  
  public void restore_screen (world_wide.screen_type screen_type)
  {
    world->screen_current = index_screen (world->screen_current)->last_screen;
    draw();
  }

  bool rememberable_screen (int key_num, int hot_key, world_wide.screen_type screen_type)
  {
    bool hit = false;
    int f1 = console.key_f1;
    int k1 = console.key_k1;
    if (hot_key > 12)
    {
      if (key_num == hot_key) hit = true;
    }
    else
    {
      if (key_num == f1 + hot_key - 1) hit = true; // 12 fn keys
      if (key_num == k1 + hot_key - 1) hit = true; // keys 1-9
    }
    if (!hit)
      return false;

    if (index_screen (screen_type) == null)
      return true; // right key stroke, but screen isn't set up yet
    world->con->cls();
    if (world->screen_current == screen_type &&
        index_screen (screen_type)->last_screen != world_wide.screen_type.none)
      restore_screen (screen_type);
    else
      remember_screen (screen_type);
    return true;
  }

  bool key_callback (IOChannel src, IOCondition cond)
  {
    int key_num = world->con->get_key();

    if (rememberable_screen (key_num, 1, world_wide.screen_type.help)) key_num = 0;
    if (rememberable_screen (key_num, 2, world_wide.screen_type.file_list)) key_num = 0;
    if (rememberable_screen (key_num, 3, world_wide.screen_type.play_list)) key_num = 0;
    if (rememberable_screen (key_num, 4, world_wide.screen_type.ext_list)) key_num = 0;
    if (rememberable_screen (key_num, '`', world_wide.screen_type.debug)) key_num = 0;

    switch (key_num)
    {
      case 0:
        break;

      case 'q':
        loop.quit();
        break;

      case console.key_backspace:
        stop();
        world->playlist_position = -1;
        draw();
        break;

      case ' ':
        switch (world->playing_state)
        {
          case world_wide.playing_type.play:
            resume_position = get_position();
            pause();
            break;

          case world_wide.playing_type.pause:
            play.seek_simple (Gst.Format.TIME, Gst.SeekFlags.FLUSH | Gst.SeekFlags.KEY_UNIT, resume_position);
            playing();
            break;
        }
        break;

      case '\\':
        advance_song();
        break;

      case ',':
        adjust_position (-5);
        break;
        
      case '.':
        adjust_position (+5);
        break;
      
      case '[':
        adjust_position (-60);
        break;
        
      case ']':
        adjust_position (+60);
        break;
      
      case '{':
        adjust_position_fraction (-1);
        break;
      
      case '}':
        adjust_position_fraction (+1);
        break;
      
      case '-':
        world->play_advance = !world->play_advance;
        draw();
        break;
      
      default:
        index_screen()->key_press (key_num);
        break;
    }

    return true;
  }
  
  public void draw()
  {
    index_screen()->draw();
    draw_counter();
  }
  
  public void draw_counter()
  {
    if (!index_screen()->has_title())
      return;

    string text;

    if (world->playing_state == world_wide.playing_type.stop)
      text = "  0:00";
    else
    {
      int64 position = get_position();
      if (position == 0)
        return; // side-effect of pressing seek key: pos = 0, work-around this
      resume_position = position;
      text = "  " + time_text (position) + "/" + time_text (get_duration());
      if (song_label != "")
        text = text + " " + song_label;
      else
      if (position * 10 / nsec > 2) // that's 0.2s into song
        text = text + " " + song_short_file_name;
    }

    world->con->print_status (text);
  }
  
  bool tick_callback()
  {
    if (auto_start_name != "")
    {
      files *a_file = (files*) world->files_array.nth_data (world->screen_files);
      a_file->play_a_song (auto_start_name);
      auto_start_name = "";
      a_file->draw();
    }

    if (auto_start_number >= 0)
    {
      world->play_screen->play_a_song (auto_start_number);
      auto_start_number = -1;
      world->play_screen->draw();
    }

    int new_screen_size = world->con->calculate_screen_size();
    if (new_screen_size != screen_size)
    {
      world->con->cls();
      screen_size = new_screen_size;
      index_screen()->draw();
    }
    
    draw_counter();
    return true;
  }

  public void tag_reciever (Gst.TagList list, string tag)
  {

    string field, data;
    // valac workarounds:
    //if (list.get_string (tag, out data)) // run-time warnings, or
    if (check_tag_exists ((void*) list, (char*) tag)) // clean
    {
      list.get_string (tag, out data);
      field = tag.down();
      if (field == "title") song_title = data;
      if (field == "artist") song_artist = data;
      if (field == "album") song_album = data;

      if (song_title != "")
      {
        if (song_artist != "")
          song_label = song_title + " - " + song_artist;
        else
          song_label = song_title;
      }

      world->debug->add ("tag: " + tag + ": " + data);
    }
    else
      world->debug->add ("empty tag: " + tag);
  }


  bool bus_callback (Gst.Bus bus, Gst.Message message)
  {
    switch (message.type)
    {
      case MessageType.EOS:
        if (world->play_advance == false)
        {
          stop();
          draw();
        }
        else
          advance_song();
        break;

      case MessageType.ERROR:
      case MessageType.WARNING:
//      case MessageType.ELEMENT:
        world->debug->add ("Stop: %x".printf (message.type));
        stop();
        world->con->cls(); // cheap, dirty hack
        world->con->refresh();
        draw();
        break;

      case MessageType.TAG:
        Gst.TagList tag_list;
        message.parse_tag (out tag_list);

        // compiler error work-arounds:
        tag_list.foreach (tag_reciever); //Gstreamer-1.0 NO LONGER THE CASE: c-compiler warnings, or
        // tag_list.foreach ((TagForeachFunc) tag_reciever); // run time errors on play, or
        //taglist_foreach_job (tag_list, tag_reciever, this); // clean
        break;
    }
    return true;
  }

  public void open_path (string path)
  {
    switch (determine_node (path))
    {
      case file_type.dir:
        start_from_new_path (world, path, true);
        break;

      case file_type.file:
        auto_start_name = get_file_from_path (path);
        start_from_new_path (world, get_base_from_path (path), true, auto_start_name);
       break;

      case file_type.m3u:
        start_from_new_path (world, get_base_from_path (path), false);
        world->screen_files = (int) world->files_array.length() - 1;
        world->play_screen = new playlist.play_start (world, path);
        auto_start_number = 0; // top of playlist
        break;

      case file_type.not_exist:
        world->debug->add ("bad path: " + path);
        break;
    }
  }

  public void begin (string path)
  {
    Timeout.add (250, tick_callback);
    var ioc = new IOChannel.unix_new (0);
    ioc.add_watch (IOCondition.IN, key_callback);
    open_path (path);
    element_make();
    loop.run();
    world->con->end();
  }
}


int main (string[] args)
{
  Gst.init (ref args);
  var player = new auditive();
  string path;
  if (args.length > 1 && args [1] != "")
  {
    if (args[1][0] == '/')
      path = args [1];
    else
      path = Environment.get_current_dir() + "/" + args [1];
  }
  else
    path = Environment.get_current_dir();
  player.begin (remove_slashes (path));
  return 0;
}

