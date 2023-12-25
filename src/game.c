#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/SDL.h"
#include "event.h"
#include "display.h"
#include "game.h"
#include "connection.h"
#include "menu.h"
#include "../include/mysql.h"

#define SDL_MAIN_HANDLED


int main(int argc, char *argv[]) {

    /* DEFINE GAME VARIABLE */

    bool in_level = false;
    int user_id;
    /*int nb_block = 0;
    int nb_supplementary_line = 0;
    int time_to_launch_server = 0;
    int nb_block_removed = 0;*/
    bool run = true;

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


    /* GAME */

    SDL_ShowCursor(SDL_DISABLE);
    giveUserId(&user_id);
    printf("user_id : %d\n", user_id);

    while (run) {
        SDL_Event event;
        SDL_Delay(1);

        while (SDL_PollEvent(&event))
            event_manager(event, &run, KEYS);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (!in_level)
            display_menu(renderer, &in_level, start_icon_texture);

        launch_level(&in_level, KEYS, user_id);

        display_cursor(renderer, cursor_texture, in_level);
        keyboard_manager(KEYS);
        SDL_RenderPresent(renderer);
    }

    return 0;
}
