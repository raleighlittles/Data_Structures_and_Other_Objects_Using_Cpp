cmake_minimum_required(VERSION 3.13)
project(chapter_15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wextra --std=c++2a")

add_executable(chapter_15 main.cpp Graph.h)
