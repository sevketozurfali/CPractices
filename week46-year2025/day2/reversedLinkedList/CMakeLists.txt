cmake_minimum_required(VERSION 4.0)
project(reversedLinkedList C)

set(CMAKE_C_STANDARD 17)

add_executable(reversedLinkedList main.c
        linkedList.c
        linkedList.h)
