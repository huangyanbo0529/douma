cmake_minimum_required(VERSION 3.15)
project(c_code C)

set(CMAKE_C_STANDARD 99)

add_executable(c_code com/douma/line/array/ArrayList.c com/douma/line/array/ArrayList.h com/douma/line/array/ArrayListTest.c)