cmake_minimum_required(VERSION 3.6)
project(Ex1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES fifo.c)
add_executable(fifo ${SOURCE_FILES})