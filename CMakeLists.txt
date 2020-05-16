cmake_minimum_required(VERSION 3.14)
project(geekal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

aux_source_directory(. DIRSRCS)

include_directories(./ ./list ./stack ./queue ./sort ./search ./tree ./graph)

add_subdirectory(list)
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(sort)
add_subdirectory(search)
add_subdirectory(tree)
add_subdirectory(graph)


add_subdirectory(example)

find_package(PkgConfig)
pkg_search_module(GLEW REQUIRED libpng)
MESSAGE(STATUS "glew dirs:" ${GLEW_INCLUDE_DIRS})
MESSAGE(STATUS "glew lib:" ${GLEW_LIBRARIES})
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})