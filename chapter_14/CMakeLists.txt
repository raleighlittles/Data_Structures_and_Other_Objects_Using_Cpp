cmake_minimum_required(VERSION 3.13)
project(chapter_14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -g -O0 -std=c++2a -ftime-report")

add_executable(chapter_14 main.cpp Person.hpp date.h Male.hpp Female.hpp MembershipRoster.hpp)
