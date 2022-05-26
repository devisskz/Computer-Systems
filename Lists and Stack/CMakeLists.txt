cmake_minimum_required(VERSION 3.11)
project(PS3 C)

set(CMAKE_C_STANDARD 99)

add_executable(PS3 main.c list.c list.h node.c node.h)