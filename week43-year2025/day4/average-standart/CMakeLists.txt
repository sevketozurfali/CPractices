cmake_minimum_required(VERSION 3.31)
project(average_standart C)

set(CMAKE_C_STANDARD 17)

add_executable(average_standart main.c)
target_link_libraries(average_standart m)