cmake_minimum_required(VERSION 3.3)
project(Connect4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    c4_engine_test.c
    connect4_engine.c
    connect4_engine.h
    CuTest.c
    CuTest.h)

add_executable(Connect4 ${SOURCE_FILES})