cmake_minimum_required(VERSION 3.20)
project(Bilyk_Lab1 C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(Bilyk_Lab1
        main.c
        math.c
        math.h
)
target_include_directories(Bilyk_Lab1 PRIVATE .)