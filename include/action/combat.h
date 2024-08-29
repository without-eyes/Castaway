#ifndef CASTAWAY_COMBAT_H
#define CASTAWAY_COMBAT_H

#include "../entities/enemy.h"
#include "../entities/passive.h"
#include "../entities/player.h"

void attack(const Attributes *attackerAttributes, Attributes *defenderAttributes);

Enemy *findAttackedEnemy(Position position, Enemy **enemyArray, int enemyCount);

Passive *findAttackedPassive(Position position, Passive **passiveArray, int passiveCount);

#endif //CASTAWAY_COMBAT_H
