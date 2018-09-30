cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 17)
project (Towers)
add_executable(Towers main.cpp peg.h towers.h towers.cpp peg.cpp)