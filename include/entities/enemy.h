#ifndef CASTAWAY_ENEMY_H
#define CASTAWAY_ENEMY_H

#include "../stats/position.h"
#include "../stats/attributes.h"

typedef struct {
    Position position;
    Attributes attributes;
} Enemy;

Enemy *initializeEnemy(Position position, int health, int damage, char symbol);

void goToPlayer(Enemy *enemy, Position playerPosition);

void moveEnemy(int y, int x, Enemy *enemy);

#endif //CASTAWAY_ENEMY_H
