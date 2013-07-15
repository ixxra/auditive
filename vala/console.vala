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


// not using curses directive: I want my own refresh() function


class console
{
  public const int key_up = Curses.Key.UP;
  public const int key_down = Curses.Key.DOWN;
  public const int key_left = Curses.Key.LEFT;
  public const int key_right = Curses.Key.RIGHT;
  public const int key_home = Curses.Key.HOME;
  public const int key_end = Curses.Key.END;
  public const int key_ppage = Curses.Key.PPAGE;
  public const int key_npage = Curses.Key.NPAGE;
  public const int key_backspace = Curses.Key.BACKSPACE;
  public const int key_shift_tab = 353;
  public const int key_f1 = 265; // could be better defined
  public const int key_k1 = '1';

  Curses.Window win;

  public int raw_lines;
  public int raw_columns;

  public console()
  {  
    Curses.initscr();
    Curses.cbreak();
    Curses.noecho();
    Curses.curs_set (0);
    win = new Curses.Window (1, 1, 0, 0);
    win.keypad (true);
  }
  
  public void end()
  {
    cls();
    Curses.endwin();
  }

  public void print_it (string text)
  {
    string txt = text;
    int len = (int) txt.length;
    
    if (len < raw_columns)
      txt = txt + string.nfill (raw_columns - len, ' ');
    if (len > raw_columns)
      txt = txt.substring (0, raw_columns);
    Curses.addstr (txt);
  }
    
  public void print_title (string text)
  {
    calculate_dimensions();
    Curses.move (0, 0);
    print_it (text);
    Curses.refresh();
  }
  
  public void print_status (string text)
  {
    calculate_dimensions();
    Curses.move (raw_lines - 1, 0);
    print_it (text);
    Curses.refresh();
  }
  
  public void print_at (int x, int y, string text)
  {
    Curses.move (y, x);
    print_it (text);
  }

  public void print_inverse_at (int x, int y, string text)
  {
    Curses.move (y, x);
    Curses.attron (Curses.Attribute.REVERSE);
    print_it (text);
    Curses.attroff (Curses.Attribute.REVERSE);
  }

  public void refresh()
  {
    Curses.refresh();
  }
  
  public void cls()
  {
    Curses.attroff (Curses.Attribute.REVERSE);
    Curses.clear();
    Curses.refresh();
    Curses.move (0, 0);
  }
  
  public int get_key()
  {
    return win.getch();
  }

  public void calculate_dimensions()
  {
    raw_lines = Curses.LINES;
    raw_columns = Curses.COLS;
  }
  
  public int calculate_screen_size()
  {
    return Curses.COLS + Curses.LINES * 10000;
  }
}

