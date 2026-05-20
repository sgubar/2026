cmake_minimum_required(VERSION 3.20)
project(Lab2 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Lab2
        main.c
        word.c
        word.h
)

target_include_directories(Lab2 PRIVATE .)