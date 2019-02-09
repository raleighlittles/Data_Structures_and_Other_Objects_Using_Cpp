cmake_minimum_required(VERSION 3.12)
project(chapter_14)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -g")

add_executable(chapter_14 main.cpp game.h TicTacTwo.h)
