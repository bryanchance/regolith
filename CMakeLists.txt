# CMake Basics
project (aura)
cmake_minimum_required(VERSION 3.4)
set(CMAKE_VERBOSE_MAKEFILE "1")

include(${CMAKE_SOURCE_DIR}/config/cmk_modules/mk_path.cmake)
mk_paths()

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/dist/bin)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/dist/bin")

include(${CMAKE_SOURCE_DIR}/config/cmk_modules/py_pp.cmake)

add_subdirectory(aura)