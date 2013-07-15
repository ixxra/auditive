
CC = gcc
LD = gcc
PKGS = glib-2.0 gobject-2.0 gstreamer-0.10 gio-2.0
CFLAGS = -O2 -g $(shell pkg-config --cflags $(PKGS))
# alternative LDFLAG: lncursesw
LDFLAGS = -lncurses $(shell pkg-config --libs $(PKGS))
ALT_LDFLAGS = -lncursesw $(shell pkg-config --libs $(PKGS))
RM = /bin/rm -f
PROG = auditive
VALA := $(wildcard *.vala)
CTEMP = $(VALA:.vala=.c)
OBJS = $(VALA:.vala=.o)
DATE = $(shell date "+%F %H:%M")
VERM = $(shell cat ../ver-mine)
VERD = $(shell cat ../ver-dist)
VERN = $(VERD) $(VERM) at $(DATE)
.SECONDARY:

$(PROG): $(OBJS) c_funcs.o
	@ echo "ld $@"
	@ $(LD) $(LDFLAGS) $(OBJS) c_funcs.o -o $@

# build with wide ncurses support
auditive.w: $(OBJS) c_funcs.o
	@ echo "ld $@"
	@ $(LD) $(LDFLAGS) $(OBJS) c_funcs.o -o $@ && mv auditive.w auditive

$(OBJS): $(CTEMP)
	@ echo "cc $*.c"
	@ $(CC) $(CFLAGS) -c $*.c

$(CTEMP): cmarker
	@ true

cmarker: $(VALA) c_funcs.o
	@ sed -i "s/Auditive999/Build $(VERN)/" help.vala
	@ echo "valac $(VALA)"
	@ valac -C --pkg glib-2.0 --pkg gstreamer-0.10 --pkg curses --pkg gio-2.0 $(VALA) && touch cmarker

c_funcs.o: c_funcs.c
	@ echo "cc $<"
	@ $(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(PROG) $(OBJS) c_funcs.o $(CTEMP) cmarker

oclean:
	$(RM) $(PROG) $(OBJS) c_funcs.o
