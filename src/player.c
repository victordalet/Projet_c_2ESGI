#include <stdbool.h>
#include "player.h"
#include "game.h"
#include "../include/sdl.h"

void move(int delta, Player *player, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]) {
    if (level[player->y / LEVEL_DIM_DIF - 1][(player->x + player->camera_x) / LEVEL_DIM_DIF + 1] != 1) {
        if (player->x + LIMIT_CAM == WINDOW_WIDTH && delta == 1)
            player->camera_x += player->speed;
        else {
            if (player->camera_x && delta == -1)
                player->camera_x -= player->speed / 2;
            player->x += player->speed * delta;
        }
    }
}

void jump(Player *player, const int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]) {
    if (level[player->y / LEVEL_DIM_DIF][(player->x + player->camera_x) / LEVEL_DIM_DIF] == 1) {
        if (!player->jump)
            player->jump = 1;
    }
}

void gravity(Player *player, const int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]) {
    if (player->jump) {
        player->jump++;
        if (player->jump < player->gravity / 2)
            player->y -= player->speed;
        else if (player->jump > player->gravity / 2) {
            player->y += player->speed;
            if (level[player->y / LEVEL_DIM_DIF][(player->x + player->camera_x) / LEVEL_DIM_DIF] == 1)
                player->jump = 0;
        }
        if (player->jump > player->gravity)
            player->jump = 0;
    } else {
        if (!level[player->y / LEVEL_DIM_DIF][(player->x + player->camera_x) / LEVEL_DIM_DIF])
            player->y += player->speed;
    }
}


void respawn(Player *player) {
    if (player->y >= WINDOW_HEIGHT || player->hp <= 0) {
        player->y = 0;
        player->x = 0;
        player->camera_x = 0;
        player->hp = 20;
    }
}

void get_item(int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y], Player *player, bool *in_game) {
    int actual_position = level[player->y / LEVEL_DIM_DIF][(player->x + player->camera_x) / LEVEL_DIM_DIF];
    switch (actual_position) {
        case 3:
            level[player->y / LEVEL_DIM_DIF][(player->x + player->camera_x) / LEVEL_DIM_DIF] = 0;
            player->hp++;
            break;
        case 5: // end map (no really items)
            player->y = 0;
            player->x = 0;
            player->camera_x = 0;
            player->hp = 20;
            *in_game = false;
            break;
        default:
            break;
    }
}