cmake_minimum_required(VERSION 4.0)
project(find_top_student C)

set(CMAKE_C_STANDARD 17)

add_executable(find_top_student main.c
        student.c
        student.h)
