#include "../../include/core/castaway.h"
#include "../../include/entities/enemy.h"
#include "../../include/entities/passive.h"

#include <stdlib.h>
#include <time.h>

void startGame() {
    initialiseScreen();
    setMap();
    srand(time(NULL));

    Player *player = initialisePlayer(getRandomPosition());

    const int enemyCount = rand() % 3;
    Enemy* enemyArray[enemyCount];
    for (int i = 0; i < enemyCount; i++) {
        Enemy* enemy = initialiseEnemy(getRandomPosition(), 10, 10, 'E');
        enemyArray[i] = enemy;
    }

    const int passiveCount = rand() % 3;
    Passive* passiveArray[passiveCount];
    for (int i = 0; i < passiveCount; i++) {
        Passive *passive = initialisePassive(getRandomPosition(), 10, 10, 'P');
        passiveArray[i] = passive;
    }

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

    free(player);
    player = NULL;
    for (int i = 0; i < enemyCount; i++) {
        free(enemyArray[i]);
        enemyArray[i] = NULL;
    }
    for (int i = 0; i < passiveCount; i++) {
        free(passiveArray[i]);
        passiveArray[i] = NULL;
    }
}

void initialiseScreen() {
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