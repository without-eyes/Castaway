#include "../../include/core/castaway.h"
#include "../../include/action/movement.h"
#include "../../include/action/input.h"
#include "../../include/core/macros.h"

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void runGame() {
    startGame();
    endGame();
}

void startGame() {
    initializeScreen();
    setMap();

    srand(time(NULL));
    Entities *entities = NULL;
    initializeEntities(&entities);

    gameLoop(entities);

    freeEntities(&entities);
}

void initializeScreen() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void setMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            mvprintw(i, j, ".");
        }
    }
}

void gameLoop(Entities *entities) {
    char input;
    while ((input = getch()) != 'q' && entities->player->attributes.isAlive) {
        handleInput(input, entities);

        moveAllEntities(entities);

        // remove dead
    }
}

void endGame() {
    endwin();
}