#include <stdio.h>
#include "../include/mysql.h"

void giveUserId(int *user_id) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

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
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

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
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

    if (mysql_query(&mysql,
                    "UPDATE PLAYERS SET nb_block,userId = (SELECT nb_block FROM PLAYERS WHERE userId = userId) + 1  ")) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    mysql_close(&mysql);
}

void end_game_query() {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

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
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

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
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

    mysql_query(&mysql, "UPDATE PLAYERS SET in_game = 2 WHERE in_game = 1");
    mysql_close(&mysql);
}

void exit_game_during_game_query(int user_id) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    int opt_use_ssl = SSL_MODE_DISABLED;
    mysql_options(&mysql, MYSQL_OPT_SSL_MODE, &opt_use_ssl);
    mysql_real_connect(&mysql, "127.0.0.1", "c_user", "project_c_password", "project_c", 3007, NULL, 0);

    char query[100];
    sprintf(query, "UPDATE PLAYERS SET in_game = 0 WHERE userId = %d", user_id);
    if (mysql_query(&mysql, query)) {
        printf("Error %u: %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        exit(1);
    }
    mysql_close(&mysql);
}

