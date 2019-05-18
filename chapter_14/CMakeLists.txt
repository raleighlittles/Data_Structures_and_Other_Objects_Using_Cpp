cmake_minimum_required(VERSION 3.13)
project(chapter_14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS "-g -O0")

add_executable(chapter_14 main.cpp game.h TicTacTwo.h game.cxx TicTacTwo.cpp connect4.h connect4.cpp)
