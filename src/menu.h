#ifndef MENU_H
#define MENU_H

void
launch_level(bool *in_level, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y], bool KEYS[323], int *number_enemies,
             int position_enemies[NUMBER_ENEMY][2], Enemy *enemies);

void init_enemies(int *number_enemies, int position_enemies[NUMBER_ENEMY][2], Enemy *enemies,
                  int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]);

#endif