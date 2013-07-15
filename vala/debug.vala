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


class dbg : screen
{
  public List<string> lines;
  const int max_lines = 100;

  public dbg (world_wide *w)
  {
    world = w;
  }

  public override bool has_title() {return false;}

  public override int get_size()
  {
    return (int) lines.length(); 
  }

  public override string get_line (uint num)
  {
    // could do a num < size check here
    return lines.nth_data (num);
  }

  public override world_wide.screen_type get_screen_type()
  {
    return world_wide.screen_type.debug;
  }

  public override void key_press (int key_num)
  {
    base.key_press (key_num);
    if (key_handled == -1)
      return;
    add ("Keycode: %d".printf (key_num));
    draw();
  }

  public void add (string text)
  {
    while (lines.length() >= max_lines)
      lines.delete_link (lines.first());
    lines.append (text);
  }

  public void alert (string text)
  {
    world->con->print_inverse_at (0, 1, "  " + text);
    add (text);
  }
}

