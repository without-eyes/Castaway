#include "../../include/core/castaway.h"
#include "../../include/entities/entities.h"
#include "../../include/core/movement.h"

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

    Player *player = NULL;
    int enemyCount = rand() % 3;
    Enemy **enemyArray = NULL;
    int passiveCount = rand() % 3;
    Passive **passiveArray = NULL;
    initializeEntities(&player, &enemyArray, enemyCount, &passiveArray, passiveCount);

    char input;
    while ((input = getch()) != 'q' && player->attributes.isAlive) {
        handleInput(input, player, enemyArray, enemyCount, passiveArray, passiveCount);

        moveAllEntities(player, enemyArray, enemyCount, passiveArray, passiveCount);

        // remove dead
    }

    freeEntities(&player, &enemyArray, enemyCount, &passiveArray, passiveCount);
}

void initializeScreen() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void setMap() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 70; j++) {
            mvprintw(i, j, ".");
        }
    }
}

void endGame() {
    endwin();
}