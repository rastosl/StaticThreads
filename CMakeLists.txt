# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("StaticThreads")

set( BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libs" )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE STRING "exe output dir" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE STRING "libs output dir" )

# Include sub-projects.
add_subdirectory ("SingletonWithThread")
add_subdirectory ("StaticThreads")
