#ifndef CASTAWAY_ENEMY_H
#define CASTAWAY_ENEMY_H

#include "../core/movement.h"
#include "../../include/entities/player.h"

typedef struct Enemy {
    Attributes attributes;
} Enemy;

Enemy* initialiseEnemy();
void goToPlayer(Enemy* enemy, Player* player);
void moveEnemy(const short y, const short x, Enemy* enemy);

#endif //CASTAWAY_ENEMY_H
