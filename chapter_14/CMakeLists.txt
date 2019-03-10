cmake_minimum_required(VERSION 3.12)
project(chapter_14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS "-g -O0 -v")

find_package(Boost COMPONENTS locale REQUIRED)
include_directories("usr/lib/")

add_executable(chapter_14 main.cpp game.h TicTacTwo.hpp)
target_link_libraries(chapter_14 ${Boost_LIBRARIES})
