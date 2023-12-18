#include <memory.h>
#include "player.h"
#include "enemy.h"


void get_number_and_position_enemies(int *number_enemies, int position_enemies[NUMBER_ENEMY][2],
                                     int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]) {
    int nb = 0;
    int array_position_enemies[NUMBER_ENEMY][2] = {0};
    for (int i = 0; i < DIMENSION_LEVEL1_X; i++) {
        for (int j = 0; j < DIMENSION_LEVEL1_Y; j++) {
            if (level[i][j] == 2) {
                array_position_enemies[nb][0] = j * LEVEL_DIM_DIF;
                array_position_enemies[nb][1] = i * LEVEL_DIM_DIF;
                nb++;
            }
        }
    }
    *number_enemies = nb;
    memcpy(position_enemies, array_position_enemies, sizeof(array_position_enemies));
}

void resurrect_enemy(Player player, Enemy *enemy) {
    if (player.x == 0 && player.y == 0)
        enemy->hp = 50;
}