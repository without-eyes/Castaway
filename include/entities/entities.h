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

void createPlayer(Player **player);

void createEnemies(Enemy ***enemyArray, int *enemyCount);

void createPassive(Passive ***passiveArray, int *passiveCount);

void freeEntities(Entities **entities);

void freePlayer(Player **player);

void freeEnemies(Enemy ***enemyArray, int enemyCount);

void freePassive(Passive ***passiveArray, int passiveCount);

#endif //CASTAWAY_ENTITIES_H
