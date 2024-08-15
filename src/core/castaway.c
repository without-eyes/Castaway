#include "../../include/core/castaway.h"
#include "../../include/action/input.h"
#include "../../include/action/action.h"
#include "../../include/utils/draw.h"
#include "../../include/map/map.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void runGame() {
    startGame();
    endGame();
}

void startGame() {
    initializeScreen();
    srand(time(NULL));

    setMap();

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
    initColors();
}

void gameLoop(Entities *entities) {
    char input;
    while ((input = getch()) != 'q' && entities->player->attributes.isAlive) {
        drawMapAroundPlayer(entities->player);

        showHUD(entities->player);

        handleInput(input, entities);

        actionEntities(entities);

        playerDeathSituation(entities->player);

        removeDeadEntities(&entities);
    }
}

void endGame() {
    endwin();
}