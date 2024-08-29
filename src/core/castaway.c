#include "../../include/core/castaway.h"
#include "../../include/action/input.h"
#include "../../include/action/action.h"
#include "../../include/utils/draw.h"
#include "../../include/map/map.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void runGame(void) {
    startGame();
    endGame();
}

void startGame(void) {
    initializeScreen();
    srand(time(NULL));

    setMap();

    Entities *entities = NULL;
    initializeEntities(&entities);

    showHUD(entities->player);
    gameLoop(entities);

    freeEntities(&entities);
}

void initializeScreen(void) {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    initColors();
}

void gameLoop(Entities *entities) {
    char input;
    while ((input = getch()) != 'q' && isAlive(entities->player->attributes)) {
        drawFrame(entities);
        handleInput(input, entities);
        executeEntitiesActions(entities);
        playerDeathSituation(entities->player);
        removeDeadEntities(&entities);
    }
}

void endGame(void) {
    endwin();
}