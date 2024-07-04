#ifndef CASTAWAY_ENTITIES_H
#define CASTAWAY_ENTITIES_H

#include "player.h"
#include "enemy.h"
#include "passive.h"

void initializeEntities(Player** player, Enemy** enemyArray, int enemyCount, Passive** passiveArray, int passiveCount);

void createPlayer(Player** player);

void createEnemies(Enemy** enemyArray, int enemyCount);

void createPassive(Passive** passiveArray, int passiveCount);

void freeEntities(Player** player, Enemy** enemyArray, int enemyCount, Passive** passiveArray, int passiveCount);

#endif //CASTAWAY_ENTITIES_H
