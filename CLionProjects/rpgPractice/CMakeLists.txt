cmake_minimum_required(VERSION 3.20)
project(rpgPractice C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(rpgPractice main.c
        CharacterMovement.h
        rpgFunctions.c
        rpgFunctions.h)
target_link_libraries(rpgPractice raylib)