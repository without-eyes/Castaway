#ifndef CASTAWAY_ACTION_H
#define CASTAWAY_ACTION_H

#include "../stats/position.h"
#include "../entities/entities.h"

void executePlayerAction(Position newPosition, Entities *entities);

void executeEntitiesActions(Entities *entities);

void executeEnemiesActions(Enemy **enemyArray, int enemyCount, Player *player);

void executePassivesActions(Passive **passiveArray, int passiveCount);

#endif //CASTAWAY_ACTION_H
