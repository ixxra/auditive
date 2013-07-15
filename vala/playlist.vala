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



class playlist : screen
{
  public string m3u_path;
  public List<string> entry;
  int playlist_position_number = -1;
  
  public playlist.play_start (world_wide *w, string full_path)
  {
    world = w;
    m3u_path = remove_slashes (full_path);
    world->playlist_position = -1;

    try
    {
      string line;
      var file = File.new_for_path (m3u_path);
      var in_stream = new DataInputStream (file.read (null));
      while ((line = in_stream.read_line (null, null)) != null)
      {
        if (line != "")
          entry.append (line);
      }
    }
    catch (Error err)
    {
      world->debug->add ("Read text file error: " + m3u_path + ": " + err.message);
    }
  }

  public override string get_title()
  {
    if (m3u_path == "")
      return "";
    return "  " + get_file_from_path (m3u_path);
  }

  public override int get_size()
  {
    return (int) entry.length(); 
  }

  public override string calc_target (uint num)
  {
    return find_song_path (num);
  }
  
  public override string get_line (uint num)
  {
    string prefix = "  ";
    if (world->playing_screen == (screen*) this && num == playlist_position_number)
      prefix = list_prefix();
    return prefix + get_file_from_path (entry.nth_data (num));
  }

  public override world_wide.screen_type get_screen_type()
  {
    return world_wide.screen_type.play_list;
  }

  string find_song_path (uint num)
  // returns full path
  {
    string filename;
    
    filename = entry.nth_data (num);
    if (filename.substring (0, 1) == "/")
      return filename;
    else
      return remove_slashes (get_base_from_path (m3u_path) + "/" + filename);
  }
  
  // play a song for a playlist takes an integer; for file lists it is a name
  public void play_a_song (int num)
  {
    string path = "";

    if (num >= get_size())
    {
      world->player->stop();
      return;
    }
    
    path = find_song_path (num);
    world->playing_screen = (screen*) this;
    world->player->set_playing (path);
    playlist_position_number = num;
  }

  public override void advance_song()
  {
    play_a_song (playlist_position_number + 1);
  }

  public override void reset_stop()
  {
    playlist_position_number = -1;
  }
  
  public override void key_press (int key_num)
  {
    switch (key_num)
    {
      case '\n':
        play_a_song (screen_pos + row_pos);
        world->player->draw();
        break;
      
      //case world->con->key_left:
      case console.key_left:
        world->files_array.nth_data (world->screen_files)->draw();
        break;
      
      default:
        if (world->ext_screen->external_key_press (key_num) == external.key_handled.none)
          base.key_press (key_num);
        break;
    }
  }
  
  public void empty()
  {
    while (entry.length() > 0)
      entry.delete_link (entry.last());
    m3u_path = "";
    row_pos = screen_pos = 0;
  }
}

