#ifndef CASTAWAY_COMBAT_H
#define CASTAWAY_COMBAT_H

#include "../entities/enemy.h"
#include "../entities/passive.h"
#include "../entities/player.h"

void attack(const Attributes *attackerAttributes, Attributes *defenderAttributes);

void combatEnemy(const Player *player, const Enemy *enemy, bool playerTurn);

void combatPassive(const Player *player, const Passive *passive);

Enemy *findAttackedEnemy(Position position, const Enemy **enemyArray, int enemyCount);

Passive *findAttackedPassive(Position position, const Passive **passiveArray, int passiveCount);

#endif //CASTAWAY_COMBAT_H
