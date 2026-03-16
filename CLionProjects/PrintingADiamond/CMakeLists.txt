cmake_minimum_required(VERSION 4.1)
project(PrintingADiamond C)

set(CMAKE_C_STANDARD 11)

add_executable(PrintingADiamond main.c
        PrintingADiamondFunctions.c
        PrintingADiamondFunctions.h)
