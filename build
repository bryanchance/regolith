#!/bin/bash

if ! BINOC_CMAKE_PATH="$(which cmake 2>/dev/null)"; then
	if [ -f "/c/Program Files/CMake/bin/cmake.exe" ]; then
		BINOC_CMAKE_PATH="/c/Program Files/CMake/bin/cmake.exe"
	elif [ -f "/c/Program Files (x86)/CMake/bin/cmake.exe" ]; then
		BINOC_CMAKE_PATH="/c/Program Files (x86)/CMake/bin/cmake.exe"
	fi
fi

if [ -z "$BINOC_CMAKE_PATH" ]; then
	echo "Error: CMake was not found on your system."
	exit 1
fi

if [ -d ./obj-dir ]; then
	rm -rf ./obj-dir
fi

if [ -d ./obj-dir ]; then
	echo Previous obj-dir did not get purged. Please remove it manually.
	exit 1
fi

mkdir obj-dir
cd obj-dir
"$BINOC_CMAKE_PATH" ../ -G "Unix Makefiles" -DCMK_SERVER_TARGET="$1"
"$BINOC_CMAKE_PATH" --build ./
cd ..
