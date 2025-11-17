cmake_minimum_required(VERSION 4.0)
project(deleteMember C)

set(CMAKE_C_STANDARD 17)

add_executable(deleteMember main.c
        linkedList.c
        linkedList.h)
