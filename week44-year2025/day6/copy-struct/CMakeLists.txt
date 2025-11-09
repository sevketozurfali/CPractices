cmake_minimum_required(VERSION 4.0)
project(copy_struct C)

set(CMAKE_C_STANDARD 17)

add_executable(copy_struct main.c
        student.c
        student.h)
