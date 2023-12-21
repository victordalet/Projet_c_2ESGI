#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>

void draw(SDL_Renderer *renderer, int x, int y, int w, int h);

SDL_Texture *load_picture(char *url, SDL_Renderer *renderer);

void display_picture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);

void display_cursor(SDL_Renderer *renderer, SDL_Texture *texture, bool in_level);


void display_menu(SDL_Renderer *renderer, bool in_level, SDL_Texture *level_icon_texture[NUMBER_ICON_MENU]);


#endif