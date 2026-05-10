cmake_minimum_required(VERSION 3.20)
project(Bilyk_HW1 C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(Bilyk_HW1
        main.c
        dk_tool.c
        dk_tool.h
)
target_include_directories(Bilyk_HW1 PRIVATE .)