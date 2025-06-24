# modules/dynamic_string/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(dynamic_string C)

set(CMAKE_C_STANDARD 99)

file(GLOB DSTRING_SOURCES "src/*.c")
include_directories(inc)

add_library(dynamic_string STATIC ${DSTRING_SOURCES})

target_include_directories(dynamic_string PUBLIC inc)


