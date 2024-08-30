#include "../../include/core/castaway.h"
#include "../../include/action/input.h"
#include "../../include/action/action.h"
#include "../../include/utils/draw.h"
#include "../../include/map/map.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void runGame(void) {
    Entities *entities = NULL;
    startGame(&entities);
    gameLoop(entities);
    endGame(&entities);
}

void startGame(Entities **entities) {
    setScreenAttributes();
    srand(time(NULL));
    createMap();
    createEntities(entities);
}

void setScreenAttributes(void) {
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

void endGame(Entities **entities) {
    freeEntities(entities);
    endwin();
}