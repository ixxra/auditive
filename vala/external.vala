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



class method
{
  public method (int k, string n, string c)
  {
    key = k;
    name = n;
    cmd = c;
  }
  
  public int key;
  public string name;
  public string cmd;
}


class external : screen
{
  public string target = "";
  public enum key_handled {none, resync, opened}
  
  public external (world_wide *w)
  {
    world = w;
  }
  
  public override bool has_title() {return true;}

  public override string get_title()
  {
    return "  Operating on: " + get_file_from_path (target);
  }

  public override int get_size()
  {
    return (int) world->keys_array.length(); 
  }
  
  public override string get_line (uint num)
  {
    string second, third = "";
    int key = world->keys_array.nth_data (num).key;
    second = world->keys_array.nth_data (num).name;
    if (key > 32 && key < 127)
      third = " (%c)".printf (key);
    else
      if (key != 0)
        third = " (#%d)".printf (key);
    return "  " + second + third;
  }

  public override world_wide.screen_type get_screen_type()
  {
    return world_wide.screen_type.ext_list;
  }

  public key_handled external_key_press (int key_num)
  {
    for (int i = 0; i < get_size(); i++)
      if (world->keys_array.nth_data (i).key == key_num)
      {
        return execute (i);
      }
    return key_handled.none;
  }
  
  public key_handled execute (int index)
  {
    if (index >= get_size())
      return key_handled.none;

    string[] args = world->keys_array.nth_data (index).cmd.split (" ");
    for (int i = 0; i < args.length; i++)
      args [i] = args [i].replace ("?", get_file_from_path (target));

    if (args [0] == "open" && args.length == 2)
    {
      world->player->open_path (args [1]);
      return key_handled.opened;
    }

    world->con->print_status ("  Executing: " + world->keys_array.nth_data (index).name);
    
    try
    {
      string s1, s2;
      GLib.Process.spawn_sync (get_base_from_path (target), args, null,
        SpawnFlags.SEARCH_PATH, null, out s1, out s2);
    }
    catch (Error err)
    {
      world->debug->add ("Spawn error: " + err.message);
    }
    return key_handled.resync;
    // caller should resync, cls, draw now
  }
  
  public override void key_press (int key_num)
  {
    switch (key_num)
    {
      case world->con->key_left:
        world->files_array.nth_data (world->screen_files)->draw();
        break;
      
      case '\n':
        execute (screen_pos + row_pos);
        break;
     
      default:
        if (external_key_press (key_num) == key_handled.none)
          base.key_press (key_num);
        break;
    }
  }
}

