#include "../../include/core/castaway.h"
#include "../../include/entities/enemy.h"
#include "../../include/entities/passive.h"

#include <stdlib.h>
#include <time.h>

void startGame() {
    initialiseScreen();
    setMap();
    srand(time(NULL));

    Player *player = initialisePlayer();
    //Enemy* enemy = initialiseEnemy();
    Passive *cow = initialisePassive();

    unsigned char input;
    while ((input = getch()) != 'q') {
        handleInput(input, player);
        //goToPlayer(enemy, player);
        randomMovement(cow);
    }

    free(player);
    player = NULL;
    //free(enemy);
    //enemy = NULL:
    free(cow);
    cow = NULL;

}

void initialiseScreen() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void setMap() {
    for (unsigned char i = 0; i < 40; i++) {
        for (unsigned char j = 0; j < 70; j++) {
            mvprintw(i, j, ".");
        }
    }
}

void endGame() {
    endwin();
}