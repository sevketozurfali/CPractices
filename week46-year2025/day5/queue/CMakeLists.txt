cmake_minimum_required(VERSION 4.0)
project(queue C)

set(CMAKE_C_STANDARD 17)

add_executable(queue main.c
        linkedList.c
        linkedList.h)
