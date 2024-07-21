#include "../../include/entities/entities.h"
#include <stdlib.h>
#include <stdio.h>

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

void removeDeadEntities(Entities **entities) {
    removeDeadEnemies(&(*entities)->enemyArray, &(*entities)->enemyCount);
    removeDeadPassive(&(*entities)->passiveArray, &(*entities)->passiveCount);
}

void freeEntities(Entities **entities) {
    if (*entities == NULL) {
        return;
    }

    freePlayer(&((*entities)->player));
    freeEnemies(&((*entities)->enemyArray), (*entities)->enemyCount);
    freePassives(&((*entities)->passiveArray), (*entities)->passiveCount);
    free(*entities);
    *entities = NULL;
}