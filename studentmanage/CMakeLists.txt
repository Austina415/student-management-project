cmake_minimum_required(VERSION 3.29)
project(studentmanage C)

set(CMAKE_C_STANDARD 11)

add_executable(studentmanage main.c
        head.h
        studenmanage.c
)
