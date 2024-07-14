#ifndef CASTAWAY_ENEMY_H
#define CASTAWAY_ENEMY_H

#include "../core/position.h"
#include "../core/attributes.h"

typedef struct {
    Attributes attributes;
} Enemy;

Enemy *initialiseEnemy(Position position, int health, int damage, char symbol);

void goToPlayer(Enemy *enemy, Position playerPosition);

void moveEnemy(int y, int x, Enemy *enemy);

#endif //CASTAWAY_ENEMY_H
