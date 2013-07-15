project("vala_src")
cmake_minimum_required(VERSION 2.6)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
include(ValaPrecompile)
include(ValaVersion)
find_package(Vala)
ensure_vala_version("0.7.8" MINIMUM)

FILE(GLOB VALA_SRC *.vala)

vala_precompile(VALA_C
	${VALA_SRC}
PACKAGES
	gio-2.0
	gstreamer-1.0
	curses
)

add_custom_target(VALA_TARGET ALL SOURCES ${VALA_C})

install(FILES ${VALA_C} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/../src")
