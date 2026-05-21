cmake_minimum_required(VERSION 3.20)
project(Lab3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Lab3
        main.c
        tree.c
        tree.h
)

target_include_directories(Lab3 PRIVATE .)