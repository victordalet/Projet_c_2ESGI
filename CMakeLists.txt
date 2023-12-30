cmake_minimum_required(VERSION 3.27)
project(Projet_c_2ESGI C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

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
        src/list.c
        src/list.h
        src/save.c
        src/save.h
)

target_link_libraries(Projet_c_2ESGI SDL2main SDL2 libmysql winmm)
