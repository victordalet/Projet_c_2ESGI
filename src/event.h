#ifndef EVENT_H
#define EVENT_H

void event_manager(SDL_Event event, bool *run, bool KEYS[323]);

void keyboard_manager(bool KEYS[323]);

#endif