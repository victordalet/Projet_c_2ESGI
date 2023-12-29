#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/SDL.h"
#include "event.h"
#include "display.h"
#include "game.h"
#include "connection.h"
#include "menu.h"
#include "../include/mysql.h"
#include "game-management.h"
#include "tetris.h"

#define SDL_MAIN_HANDLED


int main(int argc, char *argv[]) {

    srand(time(NULL));

    /* DEFINE GAME VARIABLE */

    bool in_level = false;
    int user_id;
    bool run = true;

    struct piece piece;
    int next_piece;
    int nb_little_bad_block = 0;
    int nb_line_bad_block = 0;
    int nb_little_bad_block_opponent = 0;
    int limit_second = 0;
    int board[HEIGHT_BLOCK][WIDTH_BLOCK];

    /* DEFINE KEY EVENT */

    bool KEYS[323]; //323 is for mousse click
    for (int i = 0; i < 323; i++)
        KEYS[i] = false;
    KEYS[323] = true;

    /* SDL */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);


    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        exit(1);

    SDL_StartTextInput();

    SDL_Window *window = SDL_CreateWindow(
            "GAME PROJECT C",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_FULLSCREEN
    );


    if (!window)
        exit(1);

    SDL_GL_CreateContext(window);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);


    /* LOAD TEXTURE */
    SDL_Texture *cursor_texture = load_picture("../assets/resources/cursor.bmp", renderer);
    SDL_Texture *start_icon_texture = load_picture("../assets/resources/start.bmp", renderer);
    SDL_Texture *i_block_texture = load_picture("../assets/resources/I.bmp", renderer);
    SDL_Texture *j_block_texture = load_picture("../assets/resources/J.bmp", renderer);
    SDL_Texture *l_block_texture = load_picture("../assets/resources/L.bmp", renderer);
    SDL_Texture *o_block_texture = load_picture("../assets/resources/O.bmp", renderer);
    SDL_Texture *s_block_texture = load_picture("../assets/resources/S.bmp", renderer);
    SDL_Texture *t_block_texture = load_picture("../assets/resources/T.bmp", renderer);
    SDL_Texture *z_block_texture = load_picture("../assets/resources/Z.bmp", renderer);
    SDL_Texture *texture_piece[7] = {i_block_texture, j_block_texture, l_block_texture, o_block_texture,
                                     s_block_texture, t_block_texture, z_block_texture};
    int block_color[8][3] = {{134, 178, 240},
                             {16,  66,  137},
                             {237, 138, 42},
                             {245, 242, 46},
                             {81,  197, 38},
                             {106, 38,  197},
                             {197, 60,  38},
                             {122, 115, 114}};


    /* GAME */

    SDL_ShowCursor(SDL_DISABLE);
    giveUserId(&user_id);
    printf("user_id : %d\n", user_id);

    while (run) {
        SDL_Event event;
        SDL_Delay(1);

        while (SDL_PollEvent(&event))
            event_manager(event, &run, KEYS, &piece, board, &next_piece);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (!in_level)
            display_menu(renderer, &in_level, start_icon_texture);
        else {
            are_you_lost(&in_level, user_id, board);
            game_manager(renderer, block_color, texture_piece, board, &nb_little_bad_block_opponent,
                         &nb_line_bad_block, &next_piece, &limit_second, &nb_little_bad_block, &piece);
        }

        launch_level(&in_level, KEYS, user_id, board);

        display_cursor(renderer, cursor_texture, in_level);
        keyboard_manager(KEYS);
        SDL_RenderPresent(renderer);
    }

    return 0;
}
