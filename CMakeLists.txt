cmake_minimum_required(VERSION 3.14)
project(geekal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

aux_source_directory(. DIRSRCS)

include_directories(./ ./list)

add_subdirectory(list)

add_executable(geekal ${DIRSRCS} )

target_link_libraries(geekal List)