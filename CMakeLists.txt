cmake_minimum_required(VERSION 3.26)
project(session6_ebedded C)

set(CMAKE_C_STANDARD 11)

add_executable(session6_ebedded main.c
        math.h
        math.c)
