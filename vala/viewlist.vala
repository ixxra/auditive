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



class viewlist : playlist
{
  public viewlist.view_start (world_wide *w, string full_path)
  {
    world = w;
    m3u_path = remove_slashes (full_path);

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


  public override string get_line (uint num)
  {
    // override so no "> "
    return "  " + get_file_from_path (entry.nth_data (num));
  }


  public override world_wide.screen_type get_screen_type()
  {
    return world_wide.screen_type.view_list;
  }


  public override void key_press (int key_num)
  {
    switch (key_num)
    {
      case '\n':
        if (world->play_screen != null)
          world->play_screen->empty();
        world->play_screen = new playlist.play_start (world, m3u_path);
        world->play_screen->screen_pos = screen_pos;
        world->play_screen->row_pos = row_pos;
        world->play_screen->play_a_song (screen_pos + row_pos);
        world->play_screen->draw();
        break;
      
      default:
        base.key_press (key_num);
        break;
    }
  }
}

