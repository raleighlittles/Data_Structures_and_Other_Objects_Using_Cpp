cmake_minimum_required(VERSION 3.10)
project(chapter_6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O0 -g")

add_executable(chapter_6 main.cpp gift_list.h gift_list.cpp)
