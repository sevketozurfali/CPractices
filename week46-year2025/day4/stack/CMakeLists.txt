cmake_minimum_required(VERSION 4.0)
project(stack C)

set(CMAKE_C_STANDARD 17)

add_executable(stack main.c
        linkedList.c
        linkedList.h)
