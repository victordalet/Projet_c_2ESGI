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


void display_menu(SDL_Renderer *renderer, bool in_level, SDL_Texture *level_icon_texture[NUMBER_ICON_MENU]) {
    if (!in_level) {
        int width = WINDOW_WIDTH / (NUMBER_ICON_MENU + 1);
        int height = 200;
        for (int i = 0; i < NUMBER_ICON_MENU; i++) {
            display_picture(renderer, level_icon_texture[i], WINDOW_WIDTH / ((NUMBER_ICON_MENU + 1) * 2) + width * i,
                            WINDOW_HEIGHT / 2 - height / 2, width, height);
        }
    }
}