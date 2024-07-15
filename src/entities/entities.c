#include "../../include/entities/entities.h"
#include "../../include/core/macros.h"
#include <malloc.h>
#include <stdlib.h>

void initializeEntities(Entities **entities) {
    *entities = (Entities *) malloc(sizeof(Entities));

    (*entities)->player = NULL;
    (*entities)->enemyArray = NULL;
    (*entities)->passiveArray = NULL;
    (*entities)->enemyCount = 0;
    (*entities)->passiveCount = 0;

    createPlayer(&(*entities)->player);
    createEnemies(&(*entities)->enemyArray, &(*entities)->enemyCount);
    createPassive(&(*entities)->passiveArray, &(*entities)->passiveCount);
}

void createPlayer(Player **player) {
    *player = initialisePlayer(getRandomPosition());
}

void createEnemies(Enemy ***enemyArray, int *enemyCount) {
    *enemyCount = rand() % (TEST_ENEMY_MAX_COUNT - TEST_ENEMY_MIN_COUNT) + TEST_ENEMY_MIN_COUNT;
    *enemyArray = (Enemy **) malloc(*enemyCount * sizeof(Enemy *));
    for (int i = 0; i < *enemyCount; i++) {
        (*enemyArray)[i] = initialiseEnemy(getRandomPosition(), 15, 2, TEST_ENEMY_SYMBOL);
    }
}

void createPassive(Passive ***passiveArray, int *passiveCount) {
    *passiveCount = rand() % (TEST_PASSIVE_MAX_COUNT - TEST_PASSIVE_MIN_COUNT) + TEST_PASSIVE_MIN_COUNT;
    *passiveArray = (Passive **) malloc(*passiveCount * sizeof(Passive *));
    for (int i = 0; i < *passiveCount; i++) {
        (*passiveArray)[i] = initialisePassive(getRandomPosition(), 10, 0, TEST_PASSIVE_SYMBOL);
    }
}

void freeEntities(Entities **entities) {
    freePlayer(&((*entities)->player));
    freeEnemies(&((*entities)->enemyArray), (*entities)->enemyCount);
    freePassive(&((*entities)->passiveArray), (*entities)->passiveCount);
    free(*entities);
    *entities = NULL;
}

void freePlayer(Player **player) {
    if (*player) {
        free(*player);
        *player = NULL;
    }
}

void freeEnemies(Enemy ***enemyArray, const int enemyCount) {
    if (*enemyArray) {
        for (int i = 0; i < enemyCount; i++) {
            if ((*enemyArray)[i]) {
                free((*enemyArray)[i]);
                (*enemyArray)[i] = NULL;
            }
        }
        free(*enemyArray);
        (*enemyArray) = NULL;
    }
}

void freePassive(Passive ***passiveArray, const int passiveCount) {
    if (*passiveArray) {
        for (int i = 0; i < passiveCount; i++) {
            if ((*passiveArray)[i]) {
                free((*passiveArray)[i]);
                (*passiveArray)[i] = NULL;
            }
        }
        free(*passiveArray);
        (*passiveArray) = NULL;
    }
}
