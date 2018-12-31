cmake_minimum_required(VERSION 3.12)
project(chapter_12)

set(CMAKE_CXX_STANDARD 20)
find_package(Boost COMPONENTS locale REQUIRED)
include_directories("usr/lib/")

add_executable(chapter_12 main.cpp dictionary.h rapid_csv.h)
target_link_libraries(chapter_12 ${Boost_LIBRARIES})
