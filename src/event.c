#include "stdbool.h"
#include "../include/sdl.h"
#include "tetris_player_action.h"
#include "game.h"
#include "tetris.h"

void event_manager(SDL_Event event, bool *run, bool KEYS[323]) {
    switch (event.type) {
        case SDL_QUIT:
            *run = false;
            break;
        case SDL_KEYDOWN:
            KEYS[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            KEYS[event.key.keysym.sym] = false;
        case SDL_MOUSEBUTTONDOWN:
            KEYS[323] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            KEYS[323] = false;
            break;
        default:
            break;
    }
}

void keyboard_manager(bool KEYS[323], struct piece *piece, int board[HEIGHT_BLOCK][WIDTH_BLOCK], int *next_piece,int *speed_gravity, int user_id) {
    if (KEYS[(int) 'a'] || KEYS[(int) ' '])
        set_rotation(1, piece,board);
    if (KEYS[(int) 'd'])
        move_right(piece, board, next_piece,speed_gravity,user_id);
    if (KEYS[(int) 'q'])
        move_left(piece, board, next_piece,speed_gravity,user_id);
    if (KEYS[(int) 'z'])
        move_direct_down(piece, board, next_piece,speed_gravity,user_id);
    if (KEYS[(int) 's'])
        move_down(piece, board, next_piece,speed_gravity,user_id);
    if (!KEYS[323]) {
        KEYS[323] = true;
    }
}