cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(GridFight)

add_subdirectory(utility)


enable_testing()
add_subdirectory(test)
