#include "../../include/core/castaway.h"
#include "../../include/action/input.h"
#include "../../include/action/action.h"
#include "../../include/utils/draw.h"
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

    showHUD(entities->player);
    gameLoop(entities);

    freeEntities(&entities);
}

void initializeScreen() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void gameLoop(Entities *entities) {
    char input;
    while ((input = getch()) != 'q' && entities->player->attributes.isAlive) {
        handleInput(input, entities);

        actionEntities(entities);

        showHUD(entities->player);

        playerDeathSituation(entities->player);

        removeDeadEntities(&entities);
    }
}

void endGame() {
    endwin();
}