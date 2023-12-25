#ifndef CONNECTION_H
#define CONNECTION_H

#include "../include/mysql.h"

void giveUserId(int * user_id);

int get_status_server();

void add_block_query();

void end_game_query();

void enter_game_query(int user_id);

void launch_game_query();

void exit_game_during_game_query(int user_id);

#endif