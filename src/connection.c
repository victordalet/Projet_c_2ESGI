#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "game.h"
#include "save.h"
#include "linux_function.h"


char *get_ip() {
    FILE *fptr = fopen("../assets/conf/.env", "r");
    char env[300];
    fgets(env, 300, fptr);
    return str_split(env, '=')[1];
}


void giveUserId(int *user_id) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    MYSQL_ROW row;
    MYSQL_RES *result;
    if (mysql_query(&mysql, "INSERT INTO PLAYERS(in_game,nb_block) VALUES (0,0)")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    if (mysql_query(&mysql, "SELECT LAST_INSERT_ID() FROM PLAYERS")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    result = mysql_use_result(&mysql);
    row = mysql_fetch_row(result);
    *user_id = atoi(row[0]);
    mysql_free_result(result);
    mysql_close(&mysql);
}


int get_status_server() {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    MYSQL_RES *result;
    MYSQL_ROW row;
    if (mysql_query(&mysql, "SELECT COUNT(*) FROM PLAYERS WHERE in_game = 2")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    result = mysql_use_result(&mysql);
    row = mysql_fetch_row(result);
    if (atoi(row[0]) > 0) {
        mysql_close(&mysql);
        return 2;
    }
    mysql_free_result(result);
    if (mysql_query(&mysql, "SELECT COUNT(*) FROM PLAYERS WHERE in_game = 1")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    result = mysql_use_result(&mysql);
    row = mysql_fetch_row(result);
    if (atoi(row[0]) > 0) {
        mysql_close(&mysql);
        return 1;
    }
    mysql_close(&mysql);
    return 0;
}

void add_block_query() {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    if (mysql_query(&mysql,
                    "UPDATE PLAYERS SET nb_block = nb_block + 1")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    mysql_close(&mysql);
}

void get_block_query(int *nb_block) {
    MYSQL mysql;
    MYSQL_ROW row;
    MYSQL_RES *result;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    if (mysql_query(&mysql, "SELECT nb_block FROM PLAYERS WHERE userId = 1")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    result = mysql_use_result(&mysql);
    row = mysql_fetch_row(result);
    *nb_block = atoi(row[0]);
    mysql_free_result(result);
    mysql_close(&mysql);
}

void end_game_query() {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    if (mysql_query(&mysql, "UPDATE PLAYERS SET in_game = 0")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    mysql_close(&mysql);
}

void enter_game_query(int user_id) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    char query[100];
    sprintf(query, "UPDATE PLAYERS SET in_game = 1 WHERE userId = %d", user_id);
    mysql_query(&mysql, query);
    mysql_close(&mysql);
}

void launch_game_query() {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    mysql_query(&mysql, "UPDATE PLAYERS SET in_game = 2 WHERE in_game = 1");
    mysql_close(&mysql);
}

void exit_game_during_game_query(int user_id) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    char query[100];
    sprintf(query, "UPDATE PLAYERS SET in_game = 0 WHERE userId = %d", user_id);
    if (mysql_query(&mysql, query)) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    mysql_close(&mysql);
}

void insert_board_query(int user_id, int board[HEIGHT_BLOCK][WIDTH_BLOCK]) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    char board_string[HEIGHT_BLOCK * WIDTH_BLOCK + 1];
    int i, j, k = 0;
    for (i = 0; i < HEIGHT_BLOCK; i++) {
        for (j = 0; j < WIDTH_BLOCK; j++) {
            itoa(board[i][j], &board_string[k], 10);
            k++;
        }
    }

    save("../assets/save/board.txt", board_string);

    char query[600];
    sprintf(query, "UPDATE PLAYERS SET game = '%s' WHERE userId = %d", board_string, user_id);
    if (mysql_query(&mysql, query)) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    mysql_close(&mysql);
}


void get_board_query(int user_id, int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]) {
    MYSQL mysql;
    MYSQL_ROW row;
    MYSQL_RES *result;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;

    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, get_ip(), "root", "project_c_password", "project_c", 3007, NULL, 0);

    char query[100];
    sprintf(query, "SELECT game FROM PLAYERS  WHERE in_game= 2 and game IS NOT NULL");
    if (mysql_query(&mysql, query)) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }

    result = mysql_use_result(&mysql);
    int index_nb_other_player = 0;
    while ((row = mysql_fetch_row(result)) != NULL) {
        for (int i = 0; i < HEIGHT_BLOCK; i++) {
            for (int j = 0; j < WIDTH_BLOCK; j++) {
                char temp_string = row[0][i * WIDTH_BLOCK + j];
                other_player_board[index_nb_other_player][i][j] = atoi(&temp_string);
            }
        }
        index_nb_other_player++;
        if (index_nb_other_player == NB_OTHER_PLAYER_TO_DISPLAY)
            break;
    }
    mysql_close(&mysql);
}
