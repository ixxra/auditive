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


public enum file_type {dir, file, m3u, not_exist}


file_type determine_node (string path)
{
  var node = File.new_for_path (path);
  if (!node.query_exists())
    return file_type.not_exist;
  if (node.query_file_type (0, null) == FileType.DIRECTORY)
    return file_type.dir;
  if (path.has_suffix (".m3u"))
    return file_type.m3u;
  else
    return file_type.file;
}


string remove_slashes (string path)
{
  string ret = path;
  
  while (true)
  {
    string old = ret;
    ret = ret.replace ("//", "/");
    if (ret == old)
      break;
  }
  
  if (ret == "" || ret == "/")
    return "/";
  
  if (ret.substring (-1) == "/")
    return ret.substring (0, ret.length - 1);
  
  return ret;
}


string get_file_from_path (string full_path)
{
  string path = remove_slashes (full_path);
  
  if (path == "" || path == "/")
    return path;

  string[] bits = path.split ("/");
  return bits [bits.length - 1];
}


string get_base_from_path (string full_path)
{
  string path = remove_slashes (full_path);

  if (path == "" || path == "/")
    return path;

  for (int i = (int) path.length - 1; i > 0; i--)
  {
    if (path [i] == "/".get_char())
      return path.substring (0, i);
  }
  return path;
}


string int_to_commas (long num)
{
  string answer;
  int i, c;

  answer = num.to_string();
  
  i = answer.length;
  if (i == 0)
    return answer;
  i--;
  c = 3;

  while (i > 0)
  {
    if (--c == 0)
    {
      answer = answer.substring (0, i) + "," + answer.substring (i, -1);
      c = 3;
    }
    i--;
  }

  return answer;
}


class node
{
  public node (string n, bool d, long a, long s)
  {
    name = n;
    is_dir = d;
    age = a;
    size = s;
  }
  
  public string name;
  public bool is_dir;
  public long age;
  public long size;
}


int cmp_nodes_name (node *left, node *right)
{
  if (left->is_dir && !right->is_dir)
    return -1;
  if (!left->is_dir && right->is_dir)
    return 1;
  if (left->name == right->name)
    return 0;
  if (left->name < right->name)
    return -1;
  return 1;
}


int cmp_nodes_size (node *left, node *right)
{
  if (left->size < right->size)
    return -1;
  if (left->size > right->size)
    return 1;
  return 0;
}


int cmp_nodes_age (node *left, node *right)
{
  if (left->age < right->age)
    return -1;
  if (left->age > right->age)
    return 1;
  return 0;
}


int cmp_nodes_age_reverse (node *left, node *right)
{
  if (left->age < right->age)
    return 1;
  if (left->age > right->age)
    return -1;
  return 0;
}


class files : screen
{
  public string path;
  public List <node> entry;
  enum display_type {name, size, age, end}
  display_type display_mode;
  string playlist_position_string = "";
  int files_position;
  long max_size;
  int size_padding;

  // construtor invoked assuming adding to the end of world.lists is correct
  public files (world_wide *w, string dir_name)
  {
    world = w;
    path = remove_slashes (dir_name);
    files_position = (int) world->files_array.length(); // assumption
    world->files_array.append (this);
    rescan();
    sort_name();
  }

  void rescan()
  {
    max_size = 0;
    while (entry.length() > 0)
      entry.delete_link (entry.last());
    try
    {
      var dir = File.new_for_path (path);
      var e = dir.enumerate_children (
        FileAttribute.STANDARD_NAME + "," +
        FileAttribute.STANDARD_TYPE + "," +
        FileAttribute.STANDARD_SIZE + "," +
        FileAttribute.TIME_MODIFIED, 0, null);
      FileInfo info;
      TimeVal tv;
      bool is_dir;
      long size;
      while ((info = e.next_file (null)) != null)
      {
        tv = info.get_modification_time();
        is_dir = info.get_file_type() == FileType.DIRECTORY;
        size = is_dir ? 0 : (long) info.get_size();
        entry.append (new node (info.get_name(), is_dir, tv.tv_sec, size));
        if (size > max_size)
          max_size = size;
      }
    }
    catch (Error err)
    {
      world->debug->add ("Scan dir error: " + path + ": " + err.message);
    }
    size_padding = int_to_commas (max_size).length;
  }

  public override string get_title()
  {
   
   return "  %s%s".printf (path, path == "/" ? "" : "/");
  }

  public override int get_size()
  {
    return (int) entry.length(); 
  }

  public override string calc_target (uint num)
  {
    if (num <= entry.length())
      return remove_slashes (path + "/" + entry.nth_data (num).name);
    else
      return path;
  }
  
  public override string get_line (uint num)
  {
    string short_name = entry.nth_data (num).name; // could do a num < size check here
    string prefix = "  ";
    if (world->playing_screen == (screen*) this &&
      short_name == playlist_position_string)
      prefix = list_prefix();
    string text;
    DateTime dt;
    switch (display_mode)
    {
      case display_type.name:
        text = entry.nth_data (num).name;
        break;

      case display_type.size:
        text = int_to_commas (entry.nth_data (num).size);
        text = string.nfill (size_padding - text.length, ' ') + text + " ";
        break;

      case display_type.age:
        dt = new DateTime.from_unix_local (entry.nth_data (num).age);
        text = "%d/%02d/%02d %02d:%02d ".printf (dt.get_year(), dt.get_month(),
          dt.get_day_of_month(), dt.get_hour(), dt.get_minute());
        break;

      default:
        text = "<unhandled display type>";
        break;
    }
    string suffix = entry.nth_data (num).is_dir == true ? "/" : "";
    return prefix + text + suffix;
  }
  
  public void sort_name()
  {
    entry.sort ((CompareFunc) cmp_nodes_name);
    display_mode = display_type.name;
  }

  public void sort_size()
  {
    entry.sort ((CompareFunc) cmp_nodes_size);
    display_mode = display_type.size;
  }

  public void sort_age()
  {
    entry.sort ((CompareFunc) cmp_nodes_age);
    display_mode = display_type.age;
  }

  public void sort_age_reverse()
  {
    entry.sort ((CompareFunc) cmp_nodes_age_reverse);
    display_mode = display_type.age;
  }

  public override world_wide.screen_type get_screen_type()
  {
    return world_wide.screen_type.file_list;
  }

  public override void draw()
  {
    world->screen_files = files_position;
    base.draw();
  }

  // play a song for a file list takes a short string - no / characters
  public void play_a_song (string name)
  {
    int index = find_entry (name);
    if (index < 0)
      world->player->stop();
    else
    {
      if (world->play_screen != null)
        world->play_screen->empty();
      world->playing_screen = (screen*) this;
      world->player->set_playing (remove_slashes (path + "/" + name));
      playlist_position_string = name;
    }
  }
  
  public override void advance_song()
  {
    int index = find_entry (playlist_position_string);
    
    for (;;)
    {
      if (index < 0)
        break;
      index++;
      if (index >= entry.length())
      {
        index = -1;
        break;
      }
      if (!entry.nth_data (index).is_dir)
        break;
    }

    if (index < 0)
      world->player->stop();
    else
      play_a_song (entry.nth_data (index).name);
  }

  public override void reset_stop()
  {
    playlist_position_string = "";
  }
  
  public override void key_press (int key_num)
  {
    string name = "";
    string full_path = "";
    int index;
    uint size = get_size();
    int files_screen_count = (int) world->files_array.length();
    
    index = (int) (screen_pos + row_pos);
    if (index >= size)
      index = -1;
    else
    {
      name = entry.nth_data (index).name;
      full_path = remove_slashes (path + "/" + name);
    }

    switch (key_num)
    {
      case '\n':
        if (index < 0)
          break;
        if (entry.nth_data (index).is_dir == true)
        {
          for (int i = files_screen_count - 1; i > files_position; i--)
          {
            files* a_file = (files*) world->files_array.nth_data (i);
            delete a_file;
            world->files_array.remove (a_file);
          }
          files *new_win = new files (world, full_path);
          new_win->draw();
        }
        else
        {
          if (name.has_suffix (".m3u"))
          {
            if (world->view_screen != null)
              world->view_screen->empty();
            world->view_screen = new viewlist.view_start (world, full_path);
            world->view_screen->draw();
          }
          else
          {
            play_a_song (name);
            world->player->draw();
          }
        }
        break;
        
      case world->con->key_left:
        if (files_position <= 0)
          break;
        world->files_array.nth_data (files_position - 1)->draw();
        break;
        
      case world->con->key_right:
        if (files_position < files_screen_count - 1)
          world->files_array.nth_data (files_position + 1)->draw();
        break;

      case '\t':
        int num = (int) display_mode;
        if (++num >= (int) display_type.end)
          num = 0;
        display_mode = (display_type) num;
        draw();
        break;

      case world->con->key_shift_tab:
        if (name == "")
          break;
        rescan();
        sort();
        int new_index = find_entry (name);
        if (new_index >= 0)
          zoom_to (new_index);
        else
          screen_pos = row_pos = 0;
        draw();
        break;

      case ';':
        rescan();
        sort_age_reverse();
        screen_pos = row_pos = 0;
        display_mode = display_type.name;
        draw();
        break;

      default:
        switch (world->ext_screen->external_key_press (key_num))
        {
          case external.key_handled.resync:
            // zoom_to etc was here
            break;
          case external.key_handled.none:
            base.key_press (key_num);
            break;
        }
        break;
    }
  }

  int find_entry (string name)
  {
    int i;
    
    for (i = 0; i < entry.length(); i++)
      if (name == entry.nth_data (i).name)
        return i;

    return -1;
  }
  
  public void sort()
  {
    switch (display_mode)
    {
      case display_type.name:
        sort_name();
        break;
        
      case display_type.size:
        sort_size();
        break;
        
      case display_type.age:
        sort_age();
        break;
    }
  }

  public void zoom_to_name (string name)
  {
    int index = find_entry (name);
    if (index >= 0)
      zoom_to (index);
    return;
  }
}


void start_from_new_path (world_wide *world, string full_path, bool do_draw, string zoom_into = "")
{
  string[] bits;
  string expand, node;
  int i;
  files *last;
  
  foreach (var a_file in world->files_array)
  {
    delete a_file;
    world->files_array.remove (a_file);
  }
  
  bits = remove_slashes (full_path).split ("/");
  last = new files (world, "/");

  expand = "/";
  for (i = 0; i < bits.length; i++)
  {
    node = bits [i];
    if (node == "")
      continue;
    expand = expand + "/" + bits [i];
    last = new files (world, expand);
  }
  
  if (do_draw == false)
    return;
    
 if (zoom_into != "")
   last->zoom_to_name (zoom_into);
 last->draw();
}

