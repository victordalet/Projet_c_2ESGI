#include <stdio.h>
#include "../include/mysql.h"

void giveUserId(MYSQL mysql, int *user_id) {
    MYSQL_ROW row;
    MYSQL_RES *result;
    mysql_query(&mysql, "INSERT INTO PLAYERS(in_game,nb_block) VALUES (0,0)", 0);
    result = mysql_use_result(&mysql);
    mysql_free_result(result);
    mysql_query(&mysql, "SELECT LAST_INSERT_ID() FROM PLAYERS", 0);
    result = mysql_use_result(&mysql);
    row = mysql_fetch_row(result);
    *user_id = (int) row[0][0];
    mysql_free_result(result);
}

void init_mysql(MYSQL mysql) {
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);

    if (mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0)) {
        printf("Welcome\n");
    } else {
        printf("%s\n", mysql_get_ssl_cipher(&mysql));
        printf("Error connection\n %d", mysql_errno(&mysql));
        mysql_close(&mysql);
        exit(1);
    }
}

int get_status_server(MYSQL mysql) {
    MYSQL_RES *result;
    mysql_query(&mysql, "SELECT * FROM PLAYERS WHERE in_game = 2", 0);
    result = mysql_use_result(&mysql);
    if (mysql_fetch_row(result))
        return 2;
    mysql_free_result(result);
    mysql_query(&mysql, "SELECT * FROM PLAYERS WHERE in_game = 1", 0);
    result = mysql_use_result(&mysql);
    if (mysql_fetch_row(result))
        return 1;
    return 0;
}

void add_block_query(MYSQL mysql) {
    mysql_query(&mysql,
                "UPDATE PLAYERS SET nb_block,userId = (SELECT nb_block FROM PLAYERS WHERE userId = userId) + 1  ", 0);
    mysql_use_result(&mysql);
}

void end_game_query(MYSQL mysql) {
    mysql_query(&mysql, "UPDATE PLAYERS SET in_game = 0", 0);
    mysql_use_result(&mysql);
}

void enter_game_query(MYSQL mysql, int user_id) {
    char query[100];
    sprintf(query, "UPDATE PLAYERS SET in_game = 1 WHERE userId = %d", user_id);
    mysql_query(&mysql, query, 0);
    mysql_use_result(&mysql);
}

void launch_game_query(MYSQL mysql) {
    mysql_query(&mysql, "UPDATE PLAYERS SET in_game = 2 WHERE in_game = 1", 0);
    mysql_use_result(&mysql);
}

void exit_game_during_game_query(MYSQL mysql, int user_id) {
    char query[100];
    sprintf(query, "UPDATE PLAYERS SET in_game = 0 WHERE userId = %d", user_id);
    mysql_query(&mysql, query, 0);
    mysql_use_result(&mysql);
}

