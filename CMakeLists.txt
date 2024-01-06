cmake_minimum_required(VERSION 3.27)
project(Projet_c_2ESGI C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")


set(CMAKE_C_STANDARD 11)

add_executable(Projet_c_2ESGI
        src/game.c
        src/display.c
        src/game.h
        src/event.h
        src/event.c
        src/player.c
        src/menu.h
        src/menu.c
        src/connection.c
        src/connection.h
        src/game-management.c
        src/game-management.h
        src/tetris.c
        src/tetris.h
        src/tetris_player_action.h
        src/tetris_player_action.c
        src/tetris_piece.c
        src/tetris_piece.h
        src/tetris_front.c
        src/tetris_front.h
        src/save.c
        src/save.h
        src/linux_function.c
        src/linux_function.h
)




target_link_libraries(Projet_c_2ESGI SDL2 mysqlclient)
