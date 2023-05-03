#ifndef _AN_PLAYER_C
#define _AN_PLAYER_C

#include <curses.h>
#include <stdlib.h>
#include "window.c"


#define INIT_Y 20
#define INIT_X 10

#define MOVES_SIZE 4



void jump(struct Player *player){
    memset(player->moves, 1, MOVES_SIZE);

    player->is_standing = false;
    player->is_rising = true;
    player->move_iterator = 0;
    player->change_iterator = 0;
}


void change_y(struct Player *player){
    player->move_iterator++;
    if(player->move_iterator > MOVES_SIZE){
        player->move_iterator = 0;
        player->change_iterator++;
        if(player->change_iterator == MOVES_SIZE)
            player->is_rising = false;
        
        player->moves[player->change_iterator] -= 1;
    }
    player->y += player->moves[player->move_iterator];
    player->is_reset = false;
}



void reset_mv_buffer(struct Player *player){
    memset(player->moves, 0, MOVES_SIZE);
    player->is_reset = true;
}


void draw_player(struct Player *player){
    mvaddch(WINDOW_HEIGHT - player->previous_y, INIT_X, player->bg_element_buffer);
    player->bg_element_buffer = mvwinch(stdscr, WINDOW_HEIGHT - player->y, INIT_X);    
    mvaddch(WINDOW_HEIGHT - player->y, INIT_X, player->skin + player->is_standing * 32);
}


#endif