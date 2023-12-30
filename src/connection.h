#ifndef CONNECTION_H
#define CONNECTION_H

#include "../include/mysql.h"
#include "game.h"

void giveUserId(int * user_id);

int get_status_server();

void add_block_query();

void get_block_query(int *nb_block);

void end_game_query();

void enter_game_query(int user_id);

void launch_game_query();

void exit_game_during_game_query(int user_id);

void insert_board_query(int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK]);

#endif