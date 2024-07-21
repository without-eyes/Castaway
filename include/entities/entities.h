#ifndef CASTAWAY_ENTITIES_H
#define CASTAWAY_ENTITIES_H

#include "player.h"
#include "enemy.h"
#include "passive.h"

typedef struct {
    Player *player;
    int enemyCount;
    Enemy **enemyArray;
    int passiveCount;
    Passive **passiveArray;
} Entities;

void initializeEntities(Entities **entities);

void removeDeadEntities(Entities **entities);

void freeEntities(Entities **entities);

#endif //CASTAWAY_ENTITIES_H
