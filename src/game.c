#include <stdbool.h>
#include <stdlib.h>
#include "../include/SDL.h"
#include "player.h"
#include "event.h"
#include "display.h"
#include "enemy.h"
#include "game.h"
#include "menu.h"

#define SDL_MAIN_HANDLED


int main(int argc, char *argv[]) {

    /* DEFINE LEVEL */
    bool in_level = false;
    int level1[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y] = {0};

    /* DEFINE CHARACTER */
    struct Player main_player = {0, 0, 20, 0, 2, GRAVITY, 40, 60, 50};
    int number_enemy = 0;
    int position_enemies[NUMBER_ENEMY][2] = {0};
    Enemy *enemies = malloc(sizeof(Enemy) * number_enemy);


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
    SDL_Texture *player_picture = load_picture("../assets/resources/player.bmp", renderer);
    SDL_Texture *platform_1_texture = load_picture("../assets/resources/platform.bmp", renderer);
    SDL_Texture *enemy1_texture = load_picture("../assets/resources/enemy.bmp", renderer);
    SDL_Texture *hp_texture = load_picture("../assets/resources/heart.bmp", renderer);
    SDL_Texture *end_texture = load_picture("../assets/resources/end.bmp", renderer);
    SDL_Texture *level1_icon_texture = load_picture("../assets/resources/one.bmp", renderer);
    SDL_Texture *level2_icon_texture = load_picture("../assets/resources/two.bmp", renderer);
    SDL_Texture *level3_icon_texture = load_picture("../assets/resources/three.bmp", renderer);
    SDL_Texture *level4_icon_texture = load_picture("../assets/resources/four.bmp", renderer);
    SDL_Texture *level5_icon_texture = load_picture("../assets/resources/five.bmp", renderer);
    SDL_Texture *level_icon_texture[NUMBER_LEVEL] = {level1_icon_texture, level2_icon_texture, level3_icon_texture,
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
        launch_level(&in_level, level1, KEYS, &number_enemy, position_enemies, enemies);
        if (in_level) {
            keyboard_manager(KEYS, &main_player, level1);
            display_hp(renderer, hp_texture, main_player);
            gravity(&main_player, level1);
            respawn(&main_player);
            draw_map(renderer, level1, main_player, platform_1_texture, hp_texture, end_texture);
            get_item(level1, &main_player, &in_level);
            display_picture(renderer, player_picture, main_player.x, main_player.y - main_player.height,
                            main_player.width,
                            main_player.height);
            for (int i = 0; i < number_enemy; i++) {
                if (enemies[i].hp > 0) {
                    display_picture(renderer, enemy1_texture, enemies[i].x - main_player.camera_x,
                                    enemies[i].y - enemies[i].w, enemies[i].w,
                                    enemies[i].h);
                }
                resurrect_enemy(main_player, &enemies[i]);
            }
        }
        SDL_RenderPresent(renderer);
    }

    free(enemies);
    return 0;
}
