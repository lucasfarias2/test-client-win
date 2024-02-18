cmake_minimum_required(VERSION 3.28)
project(tdd_client C)

set(CMAKE_C_STANDARD 11)

add_executable(tdd_client WIN32 main.c
        window.h
        window.c
        gamestate.h
        gamestate.c
        game.h
        game.c
        character.c
        character.h
        input.h
        input.c)

target_link_libraries(tdd_client gdi32)