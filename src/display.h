#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include "../include/SDL.h"
#include "game.h"

void draw(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b, int a);

SDL_Texture *load_picture(char *url, SDL_Renderer *renderer);

void display_picture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);

void display_cursor(SDL_Renderer *renderer, SDL_Texture *texture, bool in_level);

void display_menu(SDL_Renderer *renderer, bool *menu, SDL_Texture *start_icon_texture, SDL_Texture *stat_texture);

void display_last_board(SDL_Renderer *renderer, int block_color[8][3], int board[HEIGHT_BLOCK][WIDTH_BLOCK],
                        SDL_Texture *home_texture);

#endif