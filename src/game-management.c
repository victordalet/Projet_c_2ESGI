#include "connection.h"
#include "../include/mysql.h"
#include "game.h"
#include <time.h>
#include <stdio.h>

void time_sleep(unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

void loading_game(int user_id) {
    printf("Loading game...\n");
    int status_game = get_status_server();
    printf("status_game : %d\n", status_game);
    if (status_game == 2) {
        while (status_game != 0) {
            time_sleep(MAX_TIME_SLEEP_TO_RETRY_ENTER_SERVER);
            status_game = get_status_server();
        }
        enter_game_query(user_id);
        loading_game(user_id);
    }
    if (status_game == 1) {
        while (status_game != 2) {
            time_sleep(MAX_TIME_SLEEP_TO_RETRY_ENTER_SERVER);
            status_game = get_status_server();
        }
    }
    if (status_game == 0) {
        enter_game_query(user_id);
        printf("Game launch in %d seconds\n", MAX_TIME_TO_LAUNCH_SERVER);
        time_sleep(MAX_TIME_TO_LAUNCH_SERVER);
        launch_game_query();
        printf("Game launch !\n");
    }
}