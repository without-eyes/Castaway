#include "../../include/core/castaway.h"
#include "../../include/action/input.h"
#include "../../include/action/action.h"
#include "../../include/core/draw.h"
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

void gameLoop(Entities *entities) {
    char input;
    while ((input = getch()) != 'q' && entities->player->attributes.isAlive) {
        handleInput(input, entities);

        actionEntities(entities);

        playerDeathSituation(entities->player);

        removeDeadEntities(&entities);
    }
}

void endGame() {
    endwin();
}