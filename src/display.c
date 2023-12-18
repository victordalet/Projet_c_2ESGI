#include "../include/SDL.h"
#include "game.h"
#include "player.h"
#include "display.h"
#include "stdbool.h"

void draw(SDL_Renderer *renderer, int x, int y, int w, int h) {

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void draw_map(SDL_Renderer *renderer, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y], Player main_player,
              SDL_Texture *texture, SDL_Texture *texture_hp, SDL_Texture *texture_end) {
    for (int i = 0; i < DIMENSION_LEVEL1_X; i++) {
        for (int j = 0; j < DIMENSION_LEVEL1_Y; j++) {
            switch (level[i][j]) {
                case 1:
                    display_picture(renderer, texture, j * LEVEL_DIM_DIF - main_player.camera_x, i * LEVEL_DIM_DIF,
                                    LEVEL_DIM_DIF, 20);
                    break;
                case 3:
                    display_picture(renderer, texture_hp, j * LEVEL_DIM_DIF - main_player.camera_x,
                                    i * LEVEL_DIM_DIF - 10,
                                    10, 10);
                    break;
                case 5:
                    display_picture(renderer, texture_end, j * LEVEL_DIM_DIF - main_player.camera_x,
                                    i * LEVEL_DIM_DIF - 10,
                                    20, 20);
                    break;
                default:
                    break;
            }
        }
    }
}

SDL_Texture *load_picture(char *url, SDL_Renderer *renderer) {
    SDL_Surface *image = SDL_LoadBMP(url);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    return texture;
}

void display_picture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h) {
    SDL_Rect params = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &params);
}

void display_cursor(SDL_Renderer *renderer, SDL_Texture *texture,bool in_level) {
    int x, y, size = 30;
    SDL_GetMouseState(&x, &y);
    if (!in_level)
        display_picture(renderer, texture, x - (size / 2), y - (size / 2), size, size);
}


void display_hp(SDL_Renderer *renderer, SDL_Texture *texture, Player player) {
    for (int i = 0; i < player.hp; i++)
        display_picture(renderer, texture, 10 + (10 * i), WINDOW_HEIGHT - 40, 10, 10);
}

void display_menu(SDL_Renderer *renderer, bool in_level, SDL_Texture *level_icon_texture[NUMBER_LEVEL]) {
    if (!in_level) {
        int width = WINDOW_WIDTH / (NUMBER_LEVEL + 1);
        int height = 200;
        for (int i = 0; i < NUMBER_LEVEL; i++) {
            display_picture(renderer, level_icon_texture[i], WINDOW_WIDTH / ((NUMBER_LEVEL + 1) * 2) + width * i,
                            WINDOW_HEIGHT / 2 - height / 2, width, height);
        }
    }
}