cmake_minimum_required(VERSION 4.0)
project(read_struct_from_file C)

set(CMAKE_C_STANDARD 17)

add_executable(read_struct_from_file main.c
        student.c
        student.h)
