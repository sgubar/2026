cmake_minimum_required(VERSION 3.20)
project(Bilyk_HW2 C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(Bilyk_HW2
        main.c
        trian.c
        trian.h
)
target_include_directories(Bilyk_HW2 PRIVATE .)