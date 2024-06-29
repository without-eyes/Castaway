#include "../../include/core/castaway.h"
#include "../../include/entities/enemy.h"
#include "../../include/entities/passive.h"

#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void startGame(Player* player) {
    initialiseScreen();
    setMap();
    srand(time(NULL));

    player = initialisePlayer();
    //Enemy* enemy = initialiseEnemy();
    Passive* cow = initialisePassive();

    unsigned char input;
    while ((input = getch()) != 'q') {
        handleInput(input, player);
        //goToPlayer(enemy, player);
        randomMovement(cow);
    }
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

void endGame(Player* player) {
    endwin();
    free(player);
}