cmake_minimum_required(VERSION 4.0)
project(register_student C)

set(CMAKE_C_STANDARD 17)

add_executable(register_student main.c
        student.c
        student.h)
