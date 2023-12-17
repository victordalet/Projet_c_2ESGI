#include "sdl.h"
#include "stdbool.h"
#include "game.h"
#include "map.h"
#include "enemy.h"


void init_enemies(int *number_enemies, int position_enemies[NUMBER_ENEMY][2], Enemy *enemies,
                  int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]) {
    get_number_and_position_enemies(number_enemies, position_enemies, level);
    for (int j = 0; j < *number_enemies; j++) {
        struct Enemy enemy = {20, position_enemies[j][0], position_enemies[j][1], 20, 50};
        enemies[j] = enemy;
    }
}


void
launch_level(bool *in_level, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y], bool KEYS[323], int *number_enemies,
             int position_enemies[NUMBER_ENEMY][2], Enemy *enemies) {
    if (!*in_level) {
        int x, y, max_height, max_width, min_height, min_width;
        SDL_GetMouseState(&x, &y);
        for (int i = 0; i < NUMBER_LEVEL; i++) {
            min_width = 20 + WINDOW_WIDTH / (NUMBER_LEVEL + 1) * i;
            min_height = WINDOW_HEIGHT / 2 - 100;
            max_width = 20 + WINDOW_WIDTH / (NUMBER_LEVEL + 1) * (i + 1);
            max_height = WINDOW_HEIGHT / 2 + 100;
            if (!KEYS[323]) {
                if ((x > min_width && x < max_width) && (y > min_height && y < max_height)) {
                    *in_level = true;
                    switch (i) {
                        case 0:
                            defined_level1(level);
                            init_enemies(number_enemies, position_enemies, enemies, level);
                            break;
                        case 1:
                            defined_level2(level);
                            init_enemies(number_enemies, position_enemies, enemies, level);
                            break;
                        case 2:
                            defined_level3(level);
                            init_enemies(number_enemies, position_enemies, enemies, level);
                            break;
                        case 3:
                            defined_level4(level);
                            init_enemies(number_enemies, position_enemies, enemies, level);
                            break;
                        case 4:
                            defined_level5(level);
                            init_enemies(number_enemies, position_enemies, enemies, level);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}
