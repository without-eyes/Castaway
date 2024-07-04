#include "../../include/entities/entities.h"

#include <malloc.h>

void initializeEntities(Player** player, Enemy** enemyArray, const int enemyCount, Passive** passiveArray, const int passiveCount) {
    createPlayer(player);
    createEnemies(enemyArray, enemyCount);
    createPassive(passiveArray, passiveCount);
}

void createPlayer(Player** player) {
    *player = initialisePlayer(getRandomPosition());
}

void createEnemies(Enemy** enemyArray, const int enemyCount) {
    *enemyArray = (Enemy*)malloc(enemyCount * sizeof(Enemy));
    for (int i = 0; i < enemyCount; i++) {
        enemyArray[i] = initialiseEnemy(getRandomPosition(), 10, 10, 'E');
    }
}

void createPassive(Passive** passiveArray, const int passiveCount) {
    *passiveArray = (Passive *)malloc(passiveCount * sizeof(Passive));
    for (int i = 0; i < passiveCount; i++) {
        passiveArray[i] = initialisePassive(getRandomPosition(), 10, 10, 'P');
    }
}

void freeEntities(Player** player, Enemy** enemyArray, int enemyCount, Passive** passiveArray, int passiveCount) {
    free(player);
    player = NULL;

    for (int i = 0; i < enemyCount; i++) {
        free(enemyArray[i]);
        enemyArray[i] = NULL;
    }
    enemyArray = NULL;

    for (int i = 0; i < passiveCount; i++) {
        free(passiveArray[i]);
        passiveArray[i] = NULL;
    }
    passiveArray = NULL;
}