Auditive is licensed under the GPLv3, whose terms are in gpl3.txt.

Following the "release early" maxim this software has a number of
missing features. Their inclusion in the future depends on difficulty,
and gstreamer looks to get quite arcane. That volume control may have
to wait.

Credit to http://github.com/jakobwesthoff/Vala_CMake for the Vala
module to cmake.

Note the pure C file c_funcs.c is used for compiler/run-time warning
workarounds.

On Debian systems version 7 of the O/S is needed because of a glib
dependency.

To compile from vala source:

tar zxf auditive-X.Y.Z.tar.gz
cd auditive-X.Y.Z/vala
cmake .
make
make install

The last command copies C source to the src directory. Change to ../build/
directory and use the normal process to build the binary.

The Makefile in this directory can be used to compile auditive on
systems where cmake is unavailable.

tar zxf auditive-X.Y.Z.tar.gz
cd auditive-X.Y.Z
cp src/*.c devel/Makefile vala/*.vala build    # (vala files needed for glob)
cd build
touch *.vala   # (if valac installed)
touch *.c      # (if no valac compiler)
make
