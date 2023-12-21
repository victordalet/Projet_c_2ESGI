#include <stdbool.h>
#include <stdlib.h>
#include "../include/SDL.h"
#include "player.h"
#include "event.h"
#include "display.h"
#include "game.h"

#define SDL_MAIN_HANDLED


int main(int argc, char *argv[]) {

    /* DEFINE LEVEL */
    bool in_level = false;

    /* DEFINE KEY EVENT */
    bool KEYS[323]; //323 is for mousse click
    for (int i = 0; i < 323; i++)
        KEYS[i] = false;
    KEYS[323] = true;

    /* SDL */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);


    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
        exit(1);

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

    bool run = true;
    SDL_ShowCursor(SDL_DISABLE);

    while (run) {
        SDL_Event event;
        SDL_Delay(1);

        while (SDL_PollEvent(&event))
            event_manager(event, &run, KEYS);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        display_menu(renderer, in_level, level_icon_texture);
        display_cursor(renderer, cursor_texture, in_level);
        if (in_level) {
            keyboard_manager(KEYS);
        }
        SDL_RenderPresent(renderer);
    }

    return 0;
}
