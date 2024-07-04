#ifndef CASTAWAY_MOVEMENT_H
#define CASTAWAY_MOVEMENT_H

#include "position.h"
#include "../entities/player.h"
#include "../entities/enemy.h"
#include "../entities/passive.h"

void moveEntity(int y, int x, Position *entityPosition, char entitySymbol);

void moveAllEntities(Player* player, Enemy** enemyArray, int enemyCount, Passive** passiveArray, int passiveCount);

#endif //CASTAWAY_MOVEMENT_H
