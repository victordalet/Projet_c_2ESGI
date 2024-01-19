#include "connection.h"
#include <mysql/mysql.h>
#include "tetris.h"
#include "tetris_front.h"
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
        enter_game_query(user_id);
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
    }
}

void game_manager(SDL_Renderer *renderer, int block_color[8][3], SDL_Texture *texture_piece[7],
                  int board[HEIGHT_BLOCK][WIDTH_BLOCK],
                  int *nb_little_bad_block_opponent,
                  int *nb_line_bad_block,
                  int *next_piece,
                  int *limit_second,
                  int *nb_little_bad_block,
                  struct piece *piece,
                  int *speed_gravity,
                  int user_id,
                  int other_player_board[NB_OTHER_PLAYER_TO_DISPLAY][HEIGHT_BLOCK][WIDTH_BLOCK]) {
    break_line(board, nb_little_bad_block_opponent, nb_line_bad_block);
    gravity(limit_second, piece, board, next_piece, speed_gravity, user_id, other_player_board);
    set_nb_bad_block(board, nb_little_bad_block, nb_little_bad_block_opponent, nb_line_bad_block);
    display_grid(renderer);
    display_next_piece(renderer, texture_piece, *next_piece);
    display_board(renderer, block_color, board);
    display_bad_piece_on_left_side(renderer, *nb_little_bad_block, *nb_little_bad_block_opponent);
    display_other_board_player_on_the_left_of_the_main_board(renderer, block_color, other_player_board);
}