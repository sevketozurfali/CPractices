cmake_minimum_required(VERSION 4.0)
project(find_avrg_grade C)

set(CMAKE_C_STANDARD 17)

add_executable(find_avrg_grade main.c
        student.c
        student.h)
