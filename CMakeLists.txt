cmake_minimum_required(VERSION 3.8)
project(snail)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/server/main.cpp)
add_executable(snail ${SOURCE_FILES})