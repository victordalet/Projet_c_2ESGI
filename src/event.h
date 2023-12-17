#ifndef EVENT_H
#define EVENT_H

void event_manager(SDL_Event event, bool *run, bool KEYS[323]);

void keyboard_manager(bool KEYS[323], Player *main_player, int level[DIMENSION_LEVEL1_X][DIMENSION_LEVEL1_Y]);

#endif