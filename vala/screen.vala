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


abstract class screen
{
  public world_wide *world;
  public int screen_pos = 0;
  public int row_pos = 0;
  public world_wide.screen_type last_screen = world_wide.screen_type.none;

  public virtual bool has_title() {return true;}
  public virtual string get_title() {return "";}
  public virtual void advance_song() {world->debug->alert ("No advance method here");}
  public abstract int get_size();
  public virtual string calc_target (uint num) {return "";}
  public abstract string get_line (uint num);
  public abstract world_wide.screen_type get_screen_type();
  public virtual void reset_stop() {}

  ~screen()
  {
    if (world->playing_screen == this)
      world->playing_screen = null;
  }
  
  public int key_handled;
  
  int window_rows()
  {
    if (has_title())
      return world->con->raw_lines - 4;
    else
      return world->con->raw_lines;
  }
    
  public virtual void draw()
  {
    string line;
    int row, row_total, row_screen;
    int index, size;

    world->screen_current = get_screen_type();
   
    size = get_size();
    if (row_pos < 0 && size > 0)
      row_pos = 0;
    if (screen_pos + row_pos >= size)
      zoom_to_last_line();
    world->con->calculate_dimensions();
    row_total = window_rows();
    if (has_title())
    {
      world->con->print_title (get_title());
      row_screen = 2;
      world->con->print_at (0, 1, "");
      world->con->print_at (0, world->con->raw_lines - 2, "");
    }
    else
    {
      row_screen = 0;
    }
    
    for (row = 0; row < row_total; row++)
    {
      index = screen_pos + row;
      if (index < size)
        line = get_line (index);
      else
        line = row == 0 ? "  (empty)" : "";
      if (row == row_pos)
        world->con->print_inverse_at (0, row_screen, line);
      else
        world->con->print_at (0, row_screen, line);
      row_screen++;
    }

    string target = calc_target (screen_pos + row_pos);
    if (target != "")
      world->ext_screen->target = target;
    
    world->con->refresh();
  }
  
  public virtual void key_press (int key_num)
  {
    world->con->calculate_dimensions();

    uint index = screen_pos + row_pos;
    int size = get_size();
    int rows = window_rows();
    key_handled = -1;
    
    switch (key_num)
    {
      case console.key_up:
        if (row_pos > 0)
          row_pos--;
        else
        if (screen_pos > 0)
          screen_pos--;
        draw();
        break;

      case console.key_down:
        if (index + 1 >= size)
          break;
        if (row_pos < rows - 1)
          row_pos++;
        else
          screen_pos++;
        draw();
        break;

      case console.key_home:
        screen_pos = 0;
        row_pos = 0;
        draw();
        break;

      case console.key_end:
        zoom_to_last_line();
        draw();
        break;

      case console.key_ppage:
        screen_pos -= rows;
        if (screen_pos < 0)
        {
          screen_pos = 0;
          row_pos = 0;
        }
        draw();
        break;

      case console.key_npage:
        screen_pos += rows;
        if (screen_pos + rows > size)
          zoom_to_last_line();
        draw();
        break;
     
      default:
        key_handled = key_num;
        break;
    }
  }

  public void zoom_to_last_line()
  {
    world->con->calculate_dimensions();
    int size = get_size();
    int rows = window_rows();

    screen_pos = size - rows;
    if (screen_pos < 0)
      screen_pos = 0;
    row_pos = rows - 1;
    if (row_pos >= size)
      row_pos = size - 1; // so row_pos can be -1
  }

  public void zoom_to (int index)
  {
    world->con->calculate_dimensions();
    int rows = window_rows();
    int last_pos;

    screen_pos = index - (rows / 2);
    if (screen_pos < 0)
    {
      screen_pos = 0;
      row_pos = index;
    }
    else
    {
      last_pos = get_size() - rows;
      if (last_pos < 0)
        last_pos = 0;
      if (screen_pos > last_pos)
        screen_pos = last_pos;
      row_pos = index - screen_pos;
    }

    if (row_pos < 0)
      row_pos = 0;
  }
  
  public string list_prefix()
  {
    return world->play_advance ? "> " : "- ";
  }
}

