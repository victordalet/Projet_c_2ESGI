#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>

void draw(SDL_Renderer *renderer, int x, int y, int w, int h);

void draw_map(SDL_Renderer *renderer, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y], Player main_player,
              SDL_Texture *texture, SDL_Texture *texture_hp, SDL_Texture *texture_end);

SDL_Texture *load_picture(char *url, SDL_Renderer *renderer);

void display_picture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);

void display_cursor(SDL_Renderer *renderer, SDL_Texture *texture, bool in_level);

void display_hp(SDL_Renderer *renderer, SDL_Texture *texture, Player player);

void display_menu(SDL_Renderer *renderer, bool in_level, SDL_Texture *level_icon_texture[NUMBER_LEVEL]);


#endif