#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"

typedef struct Enemy Enemy;
struct Enemy {
    int hp;
    int x;
    int y;
    int w;
    int h;
};

void get_number_and_position_enemies(int * number_enemies,int position_enemies[NUMBER_ENEMY][2] ,int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]);

void resurrect_enemy(Player player, Enemy *enemy);

#endif