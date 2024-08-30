#include "../../include/entities/entities.h"
#include <stdlib.h>
#include <stdio.h>

void createEntities(Entities **entities) {
    initializeEntities(entities);
    createPlayer(&(*entities)->player);
    initializeEnemyArray(&(*entities)->enemyArray, &(*entities)->enemyCount);
    createPassives(&(*entities)->passiveArray, &(*entities)->passiveCount);
}

void initializeEntities(Entities **entities) {
    *entities = (Entities *) malloc(sizeof(Entities));

    (*entities)->player = NULL;
    (*entities)->enemyArray = NULL;
    (*entities)->passiveArray = NULL;
    (*entities)->enemyCount = 0;
    (*entities)->passiveCount = 0;
}

void removeDeadEntities(Entities **entities) {
    removeDeadEnemies(&(*entities)->enemyArray, &(*entities)->enemyCount);
    removeDeadPassive(&(*entities)->passiveArray, &(*entities)->passiveCount);
}

void freeEntities(Entities **entities) {
    if (*entities == NULL) {
        return;
    }

    freePlayer(&((*entities)->player));
    freeEnemyArray(&((*entities)->enemyArray), (*entities)->enemyCount);
    freePassiveArray(&((*entities)->passiveArray), (*entities)->passiveCount);

    free(*entities);
    *entities = NULL;
}