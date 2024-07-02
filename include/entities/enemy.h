#ifndef CASTAWAY_ENEMY_H
#define CASTAWAY_ENEMY_H

#include "../core/position.h"
#include "../../include/entities/player.h"

typedef struct Enemy {
    Attributes attributes;
} Enemy;

Enemy *initialiseEnemy(Position position, int health, int damage, char symbol);

void goToPlayer(Enemy *enemy, Player *player);

void moveEnemy(int y, int x, Enemy *enemy);

#endif //CASTAWAY_ENEMY_H
