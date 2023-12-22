#ifndef CONNECTION_H
#define CONNECTION_H

#include "../include/mysql.h"

void giveUserId(MYSQL mysql,int * user_id);

void init_mysql(MYSQL mysql);

int get_status_server(MYSQL mysql);

void add_block_query(MYSQL mysql);

void end_game_query(MYSQL mysql);

void enter_game_query(MYSQL mysql, int user_id);

void launch_game_query(MYSQL mysql);

void exit_game_during_game_query(MYSQL mysql, int user_id);

#endif