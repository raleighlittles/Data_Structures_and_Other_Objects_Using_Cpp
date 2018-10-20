cmake_minimum_required(VERSION 3.10)
project(chapter_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(chapter_7 main.cpp postfix_parser.h postfix_parser.cpp)
