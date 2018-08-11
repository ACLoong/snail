cmake_minimum_required(VERSION 3.8)
project(snail)

set(CMAKE_CXX_STANDARD 11)
set(LOG_SOURCE_FILES  src/test/LogTest.cpp
                        src/common/Log/Log.cpp
                        src/common/Log/Log.h src/test/minuint/minunint.h)

set(SERVER_SOURCE_FILES src/server/main.cpp
                          src/server/server.h
                          src/server/server.cpp src/test/minuint/minunint.h)
include_directories(src)
include_directories(src/common)
include_directories(src/test)
include_directories(src/object)

add_executable(snail ${SERVER_SOURCE_FILES})
add_executable(log ${LOG_SOURCE_FILES})