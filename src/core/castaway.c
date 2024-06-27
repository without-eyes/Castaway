#include "../../include/core/castaway.h"

#include <malloc.h>

void startGame(const Player* player) {
    initialiseScreen();
    setMap();
    player = initialisePlayer();
    unsigned char input;
    while ((input = getch()) != 'q') {
        handleInput(input, player);
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