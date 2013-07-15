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


class help : screen
{
  string[] lines =
{
"Auditive 0.1.14 copyright 2010-2012 Graeme Sheppard (www.rillion.net) GPL 3.",
"",
"(scroll down for more)",
"",
"Enter      open/start play",
"Space      pause/resume",
"Bkspc      stop/rewind",
"\\          advance",
", .        back/forward 5 sec",
"[ ]        back/forward 60 sec",
"{ }        back/forward 10%",
"-          toggle auto-advance (>) or single play (-)",
"q          quit",
"",
"Left       up a directory",
"Right      child directory",
"Up etc     navigate",
"",
"Tab        cycle name-size-date view",
"Shift-Tab  sort in current view",
";          most recent sort",
"",
"F1         help / exit help",
"F2         filesystem view",
"F3         play list view",
"F4         external operations",
"1-4        alternative keys for F1-F4",
"`          debug screen",
"",
"Invocation: auditive file/dir/.m3u",
"",
"It is possible to run external operations on files within auditive. Edit",
"example-config and copy it to ~/.auditive. These may be other media players",
"for example.",
"",
"If problems occur visit the debug screen."
};
  
  public help (world_wide *w)
  {
    world = w;
  }

  public override bool has_title() {return false;}

  public override int get_size()
  {
    return (int) lines.length; 
  }
  
  public override string get_line (uint num)
  {
    // could do a num < size check here
    return lines [num];
  }

  public override world_wide.screen_type get_screen_type()
  {
    return world_wide.screen_type.help;
  }
}

