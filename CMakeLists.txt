﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Stratega")

if (WIN32)
    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()


set(COMPILER_FLAGS "")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")

option(STRATEGA_BUILD_DOCS "Enable to build the docs. Requires doxygen to be installed on the system" OFF)

# Include sub-projects.
add_subdirectory("dependencies")
add_subdirectory("Stratega")
add_subdirectory("Arena")
add_subdirectory("GUI")
add_subdirectory("Tests")

if(STRATEGA_BUILD_DOCS)
    add_subdirectory("docs")
endif()