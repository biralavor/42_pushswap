# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget sfml-system sfml-window X11 OpenGL UDev sfml-graphics Freetype)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target sfml-system
add_library(sfml-system SHARED IMPORTED)

set_target_properties(sfml-system PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/nfs/homes/umeneses/bira/42_visualizer_pushswap/build/_deps/sfml-src/include"
)

# Create imported target sfml-window
add_library(sfml-window SHARED IMPORTED)

set_target_properties(sfml-window PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/nfs/homes/umeneses/bira/42_visualizer_pushswap/build/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-system"
)

# Create imported target X11
add_library(X11 INTERFACE IMPORTED)

set_target_properties(X11 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
  INTERFACE_LINK_LIBRARIES "/usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXrandr.so"
)

# Create imported target OpenGL
add_library(OpenGL INTERFACE IMPORTED)

set_target_properties(OpenGL PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
  INTERFACE_LINK_LIBRARIES "/usr/lib/x86_64-linux-gnu/libGL.so;/usr/lib/x86_64-linux-gnu/libGLU.so"
)

# Create imported target UDev
add_library(UDev INTERFACE IMPORTED)

set_target_properties(UDev PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
  INTERFACE_LINK_LIBRARIES "/usr/lib/x86_64-linux-gnu/libudev.so"
)

# Create imported target sfml-graphics
add_library(sfml-graphics SHARED IMPORTED)

set_target_properties(sfml-graphics PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/nfs/homes/umeneses/bira/42_visualizer_pushswap/build/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-window"
)

# Create imported target Freetype
add_library(Freetype INTERFACE IMPORTED)

set_target_properties(Freetype PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include/freetype2"
  INTERFACE_LINK_LIBRARIES "/usr/lib/x86_64-linux-gnu/libfreetype.so"
)

# Import target "sfml-system" for configuration ""
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/nfs/homes/umeneses/bira/42_visualizer_pushswap/build/_deps/sfml-build/lib/libsfml-system.so.2.5.1"
  IMPORTED_SONAME_NOCONFIG "libsfml-system.so.2.5"
  )

# Import target "sfml-window" for configuration ""
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/nfs/homes/umeneses/bira/42_visualizer_pushswap/build/_deps/sfml-build/lib/libsfml-window.so.2.5.1"
  IMPORTED_SONAME_NOCONFIG "libsfml-window.so.2.5"
  )

# Import target "sfml-graphics" for configuration ""
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/nfs/homes/umeneses/bira/42_visualizer_pushswap/build/_deps/sfml-build/lib/libsfml-graphics.so.2.5.1"
  IMPORTED_SONAME_NOCONFIG "libsfml-graphics.so.2.5"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
