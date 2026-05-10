cmake_minimum_required(VERSION 3.20)
project(Bilyk_HW3 C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(Bilyk_HW3
        main.c
        point.c
        triangle.c
        array.c
)

target_include_directories(Bilyk_HW3 PRIVATE .)