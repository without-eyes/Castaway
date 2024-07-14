#ifndef CASTAWAY_COMBAT_H
#define CASTAWAY_COMBAT_H

#include "../entities/enemy.h"
#include "../entities/passive.h"
#include "../entities/player.h"

void combatEnemy(Player* player, Enemy* enemy, bool playerTurn);

void combatPassive(Player* player, Passive* passive);

Enemy* findAttackedEnemy(Enemy **enemyArray, int enemyCount, int y, int x);

Passive* findAttackedPassive(Passive **passiveArray, int passiveCount, int y, int x);

#endif //CASTAWAY_COMBAT_H
