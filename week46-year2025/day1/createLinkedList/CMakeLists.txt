cmake_minimum_required(VERSION 4.0)
project(createLinkedList C)

set(CMAKE_C_STANDARD 17)

add_executable(createLinkedList main.c
        linkedList.c
        linkedList.h)
