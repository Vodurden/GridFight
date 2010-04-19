cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -std=c++0x")

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

project(GridFight)

add_subdirectory(utility)
add_subdirectory(core)
add_subdirectory(interface)

enable_testing()
add_subdirectory(test)

add_executable(GridFight main.cpp)
target_link_libraries(GridFight
	GF_CORE
	)
