#include <stdbool.h>
#include <stdlib.h>
#include "../include/SDL.h"
#include "event.h"
#include "display.h"
#include "game.h"
#include "connection.h"
#include "../include/mysql.h"

#define SDL_MAIN_HANDLED


int main(int argc, char *argv[]) {

    /* INIT MYSQL */

    MYSQL mysql;
    init_mysql(mysql);

    /* DEFINE GAME VARIABLE */

    bool in_level = false;
    int user_id;
    int nb_block = 0;
    int nb_supplementary_line = 0;
    int time_to_launch_server = 0;
    int nb_block_removed = 0;
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
    SDL_Texture *level1_icon_texture = load_picture("../assets/resources/one.bmp", renderer);
    SDL_Texture *level2_icon_texture = load_picture("../assets/resources/two.bmp", renderer);
    SDL_Texture *level3_icon_texture = load_picture("../assets/resources/three.bmp", renderer);
    SDL_Texture *level4_icon_texture = load_picture("../assets/resources/four.bmp", renderer);
    SDL_Texture *level5_icon_texture = load_picture("../assets/resources/five.bmp", renderer);
    SDL_Texture *level_icon_texture[NUMBER_ICON_MENU] = {level1_icon_texture, level2_icon_texture, level3_icon_texture,
                                                         level4_icon_texture, level5_icon_texture};


    /* GAME */

    SDL_ShowCursor(SDL_DISABLE);
    giveUserId(mysql, &user_id);

    while (run) {
        SDL_Event event;
        SDL_Delay(1);

        while (SDL_PollEvent(&event))
            event_manager(event, &run, KEYS);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (!in_level)
            display_menu(renderer, &in_level, level_icon_texture);

        display_cursor(renderer, cursor_texture, in_level);
        keyboard_manager(KEYS);
        SDL_RenderPresent(renderer);
    }

    mysql_close(&mysql);
    return 0;
}
