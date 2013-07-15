Auditive readme

A gstreamer, ncurses based music player. Plays any file gstreamer is
capable of, and supports .m3u playlists.

Requirements

- gstreamer + development packages
  gstreamer0.10, libgstreamer0.10-dev,
  gstreamer0.10-plugins-base, gstreamer0.10-plugins-good
- ncurses development package (libncurses5-dev)
- the glib, gobject, gio packages version 2.26
  usually found altogether in libglib2.0(-dev)
- a C compiler
- cmake (preferred)
- make

Auditive is written in Vala generated C. Vala does not need to be installed
for this program to be compiled. Developers who wish to tinker, extend or
distribute the program please look in the devel directory.

Compilation

$ tar zxf auditive-X.Y.Z.tar.gz
$ cd auditive-X.Y.Z/build
$ rm -rf ../build/*
$ cmake ../src

# if cmake fails due to missing libraries, install them and try again:
# rm -rf ../build/* ; cmake ../src

$ make -j2
# make install

Usage

When running, browse for the media with the four arrow keys and the enter
key. Note that left goes up a directory. Press F1 for various other
key functions and help. Media information is recorded in the debug screen.

Configuration file

This is ~/.auditive, and at this time contains entries to launch other
media players. Copy example-config to ~/.auditive and edit it with $EDITOR
to get started.

Author

graeme at rillion.net
