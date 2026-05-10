cmake_minimum_required(VERSION 3.20)
project(Bilyk_HW4 C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Bilyk_HW4
        main.c
        list.c
)

target_include_directories(Bilyk_HW4 PRIVATE .)