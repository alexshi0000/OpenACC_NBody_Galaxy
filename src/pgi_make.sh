#!/bin/bash
#
#simple build system created for my c++ projects
#
#Project Tree Contents
# - bin			(where the binaries go)
# - build		(where build files go)
# - doc			(documentation)
# - include		(header files)
# - lib			(external libraries)
# - src			(src files)
# - test		(test src files)

function build() {
	CPPVERSION="-std=c++14 -acc -ta=tesla:cc60 -Minfo=accel "		#version of c++
	SRCDIR="../src"													#source directory
	BUILDDIR="../build"												#build directory
	BINDIR="../bin"													#binary directory
	LIB=" -lGL -lGLU -lglut "										#libraries to be linked
	OBJECTFILES=""													#object files created
	BINARIES=("main" "main.exe")									#name of binaries to be created, one for linux, one for windows
	for ENTRY in *.cpp
	do
		pgc++ $CPPVERSION -c $ENTRY $LIB							#compile src to object file
	done
	for ENTRY in *.o
	do
		OBJECTFILES=$OBJECTFILES" "$ENTRY
		mv -f $ENTRY $BUILDDIR										#move object files to build dir from source dir
	done
	cd $BUILDDIR													#change dir to build dir
	for BIN in ${BINARIES[*]}
	do
		pgc++ $CPPVERSION $OBJECTFILES -o $BIN $LIB					#link object files using g++
		mv -f $BIN $BINDIR											#move binaries to binary dir
	done
}

build																#run build function (build function runs in subpath)
