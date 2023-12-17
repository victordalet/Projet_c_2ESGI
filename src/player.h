#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "stdbool.h"

typedef struct Player Player;
struct Player {
    int x;
    int y;
    int hp;
    int jump;
    int speed;
    int gravity;
    int width;
    int height;
    int camera_x;
};

void move(int delta, Player *player, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]);

void jump(Player *player, const int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]);

void gravity(Player *player, const int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]);

void respawn(Player *player);

void get_item(int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y], Player *player, bool *in_game);


#endif