#ifndef _AN_ANGRYJUMPER_C 
#define _AN_ANGRYJUMPER_C 

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "iofunc.c"
#include "menu.c"
#include "setup_curses.c"
#include "player.c"
#include "objects.c"
#include "window.c"


void game_loop(struct Player *player, int *platforms){
    char key;

    // platforms_generator(platforms);
    draw_whole_platforms(platforms);
    while((key = getch()) != 10){   

        player->is_standing = false; 
        for(int i = 0; i < PLATFORMS_SIZE; i += 3){
            draw_platforms(player, platforms, i);                        
            check_if_standing(player, platforms, i);

            if(player->x > platforms[PLATFORMS_SIZE/2 + 2])
                platforms_generator(platforms); 
            

            mvprintw(i/3, 30, "   %i, %i, %i   ", platforms[i], platforms[i+1], platforms[i+2]);
        }
        player->previous_y = player->y; 


        if((key == 'w' || key == 'W' || key == 3) && player->is_standing)
            jump(player);
        
        if((key == 's' || key == 'S' || key == 2) && player->is_standing)
             if((key == 's' || key == 'S' || key == 2) && player->is_standing)
                if((key == 's' || key == 'S' || key == 2) && player->is_standing)
                    if((key == 's' || key == 'S' || key == 2) && player->is_standing)
                        player->y -= 1;
        
        if(!player->is_standing)
            change_y(player);
        
        draw_player(player);
        if(player->is_standing && !player->is_reset)
            reset_mv_buffer(player);       
        

        player->x++;
        usleep(33333);
    }
}


int main(){
    char *username = 5;
    struct Player *player = init_player();
    int *objects = init_platforms();

    init_curses();
    check_win_size();

    /* TODO: Make welcome screen*/
    main_menu(username);
       
    nodelay(stdscr, TRUE);
    game_loop(player, objects);

    getch();
    end_curses();
}


#endif

