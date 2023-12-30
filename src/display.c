#include <stdio.h>
#include "../include/SDL.h"
#include "game.h"
#include "player.h"
#include "display.h"
#include "stdbool.h"

void draw(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b, int a) {

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, a, g, b, r);
    SDL_RenderDrawRect(renderer, &rect);
}


SDL_Texture *load_picture(char *url, SDL_Renderer *renderer) {
    SDL_Surface *image = SDL_LoadBMP(url);
    if (image == NULL) {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    return texture;
}

void display_picture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h) {
    SDL_Rect params = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &params);
}

void display_cursor(SDL_Renderer *renderer, SDL_Texture *texture, bool in_level) {
    int x, y, size = 30;
    SDL_GetMouseState(&x, &y);
    if (!in_level)
        display_picture(renderer, texture, x - (size / 2), y - (size / 2), size, size);
}


void display_menu(SDL_Renderer *renderer, bool *menu, SDL_Texture *start_icon_texture) {
    int width = 100;
    int height = 100;
    display_picture(renderer, start_icon_texture, WINDOW_WIDTH / 2 - (width / 2),
                    WINDOW_HEIGHT / 2 - height / 2, width, height);



}

void display_text(SDL_Renderer *renderer, char *text) {
    return;
}