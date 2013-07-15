project("auditive" C)
cmake_minimum_required(VERSION 2.6)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

find_package(PkgConfig)
pkg_check_modules(GLIB REQUIRED "glib-2.0 >= 2.26.0")
pkg_check_modules(GOBJECT REQUIRED gobject-2.0)
pkg_check_modules(GIO REQUIRED gio-2.0)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

INCLUDE(FindCurses)
IF(NOT CURSES_HAVE_CURSES_H)
	MESSAGE (FATAL_ERROR "curses development files not found")
ENDIF(NOT CURSES_HAVE_CURSES_H)

set(CFLAGS
	${GLIB_CFLAGS} ${GLIB_CFLAGS_OTHER}
	${GOBJECT_CFLAGS} ${GOBJECT_CFLAGS_OTHER}
	${GIO_CFLAGS} ${GIO_CFLAGS_OTHER}
	${GSTREAMER_CFLAGS} ${GSTREAMER_CFLAGS_OTHER}
)

add_definitions(${CFLAGS})

set(LIBS
	${GLIB_LIBRARIES}
	${GOBJECT_LIBRARIES}
	${GIO_LIBRARIES}
	${GSTREAMER_LIBRARIES}
)

link_libraries(${LIBS} -lncurses)

set(LIB_PATHS
	${GLIB_LIBRARY_DIRS}
	${GOBJECT_LIBRARY_DIRS}
	${GIO_LIBRARY_DIRS}
	${GSTREAMER_LIBRARY_DIRS}
)

link_directories (${LIB_PATHS})

FILE (GLOB C_SRC *.c)
	
add_executable (auditive ${C_SRC})

install(TARGETS 
	auditive
RUNTIME
DESTINATION
	bin
)

install(FILES
	auditive.1
DESTINATION
	${CMAKE_INSTALL_PREFIX}/share/man/man1
)
