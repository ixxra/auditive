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


class world_wide
{
  public console *con = new console();
  public auditive *player;
  public playlist *play_screen = null;
  public viewlist *view_screen = null;
  public external *ext_screen = null;
  public dbg *debug = null;
  public help *help_screen = null;

  public List <files*> files_array;
  public List <method> keys_array;
  public screen_type screen_current;
  public playing_type playing_state;
  public int screen_files;
  public bool play_advance = true;
  public screen *playing_screen = null;
  public int playlist_position = -1;
  
  public enum screen_type {none, file_list, view_list, play_list, ext_list, debug, help}
  public enum playing_type {stop, play, pause}
}

