cmake_minimum_required(VERSION 4.1)
project(my_vector C)

set(CMAKE_C_STANDARD 11)

add_library(my_vector STATIC my_vector.c
        my_vector.c
        my_vector.h
)
