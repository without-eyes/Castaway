#include "../../include/core/castaway.h"
#include "../../include/entities/entities.h"

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

    Player* player = NULL;
    const int enemyCount = rand() % 3;
    Enemy* enemyArray[enemyCount];
    const int passiveCount = rand() % 3;
    Passive* passiveArray[passiveCount];
    initializeEntities(&player, enemyArray, enemyCount, passiveArray, passiveCount);

    char input;
    while ((input = getch()) != 'q') {
        handleInput(input, player);

        for (int i = 0; i < enemyCount; i++) {
            goToPlayer(enemyArray[i], player);
        }

        for (int i = 0; i < passiveCount; i++) {
            randomMovement(passiveArray[i]);
        }

    }

    freeEntities(&player, enemyArray, enemyCount, passiveArray, passiveCount);
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