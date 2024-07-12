#include "../../include/entities/entities.h"

#include <malloc.h>

void initializeEntities(Player **player, Enemy ***enemyArray, const int enemyCount, Passive ***passiveArray,
                        const int passiveCount) {
    createPlayer(player);
    createEnemies(enemyArray, enemyCount);
    createPassive(passiveArray, passiveCount);
}

void createPlayer(Player **player) {
    *player = initialisePlayer(getRandomPosition());
}

void createEnemies(Enemy ***enemyArray, const int enemyCount) {
    *enemyArray = (Enemy **) malloc(enemyCount * sizeof(Enemy *));
    for (int i = 0; i < enemyCount; i++) {
        (*enemyArray)[i] = initialiseEnemy(getRandomPosition(), 10, 10, 'E');
    }
}

void createPassive(Passive ***passiveArray, const int passiveCount) {
    *passiveArray = (Passive **) malloc(passiveCount * sizeof(Passive *));
    for (int i = 0; i < passiveCount; i++) {
        (*passiveArray)[i] = initialisePassive(getRandomPosition(), 10, 10, 'P');
    }
}

void freeEntities(Player **player, Enemy ***enemyArray, int enemyCount, Passive ***passiveArray, int passiveCount) {
    if (*player) {
        free(*player);
        *player = NULL;
    }

    if (*enemyArray) {
        for (int i = 0; i < enemyCount; i++) {
            if ((*enemyArray)[i]) {
                free((*enemyArray)[i]);
                (*enemyArray)[i] = NULL;
            }
        }
        free(*enemyArray);
        *enemyArray = NULL;
    }

    if (*passiveArray) {
        for (int i = 0; i < passiveCount; i++) {
            if ((*passiveArray)[i]) {
                free((*passiveArray)[i]);
                (*passiveArray)[i] = NULL;
            }
        }
        free(*passiveArray);
        *passiveArray = NULL;
    }
}

