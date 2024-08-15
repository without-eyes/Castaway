#ifndef CASTAWAY_ACTION_H
#define CASTAWAY_ACTION_H

#include "../stats/position.h"
#include "../entities/entities.h"

void actionPlayer(Position newPosition, Entities *entities);

void actionEntities(Entities *entities);

void actionEnemies(Enemy **enemyArray, int enemyCount, Player *player);

void actionPassives(Passive **passiveArray, int passiveCount);

#endif //CASTAWAY_ACTION_H
