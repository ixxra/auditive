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


void config_setup (world_wide *world)
{
  string cfg_file = Environment.get_home_dir() + "/.auditive";
  world->keys_array = new GLib.List <method>();

  try
  {
    string line;
    var file = File.new_for_path (cfg_file);
    
    if (!file.query_exists (null))
    {
      world->debug->add ("Non-fatal: no cfg " + cfg_file);
      return;
    }

    world->debug->add ("reading " + cfg_file);
    var in_stream = new DataInputStream (file.read (null));
    int count = 0;
    bool good;
    while ((line = in_stream.read_line (null, null)) != null)
    {
      count++;
      if (line == "" || line [0] == '#')
        continue;
      bool empty = true;
      for (int index = 0; index < line.length; index++)
        if (line [index] != ' ' && line [index] != '\t')
        {
          empty = false;
          break;
        }
      if (empty)
        continue;
      good = false;
      while (true)
      {
        if (line == "advance=y")
        {
          world->play_advance = true;
          good = true;
          break;
        }
        if (line == "advance=n")
        {
          world->play_advance = false;
          good = true;
          break;
        }
        
        if (line [0:4] != "ext=")
          break;
        string[] bits = line.substring (4).split (",", 3);
        if (bits.length != 3)
          break;
        if (bits [1] == "" || bits [2] == "")
          break;
        int keystroke;
        if (bits [0] == "")
          keystroke = 0;
        else
        {
          if (bits [0][0] == '"')
          {
            if (bits [0].length != 3 || bits [0][2] != '"')
              break;
            keystroke = (char) bits [0][1];
          }
          else
          {
            keystroke =  int.parse (bits [0]);
            if (keystroke == 0)
              break;
          }
        }
        world->keys_array.append (new method (keystroke, bits [1], bits [2]));
        good = true;
        break;
      }
      if (!good)
      {
        world->debug->add ("bad cfg at line " + count.to_string());
        world->debug->add (count.to_string() + ": " + line);
        break;
      }
    }
  }
  catch (Error err)
  {
    world->debug->add (cfg_file + ": " + err.message);
  }
}

