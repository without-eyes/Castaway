#ifndef CASTAWAY_ENEMY_H
#define CASTAWAY_ENEMY_H

#include "../stats/position.h"
#include "../stats/attributes.h"
#include "../map/location.h"

typedef struct {
    Location location;
    Attributes attributes;
} Enemy;

Enemy *initializeEnemy(Position position, int health, int damage, chtype symbol);

void initializeEnemyArray(Enemy ***enemyArray, int *enemyCount);

void removeDeadEnemies(Enemy ***enemyArray, int *enemyCount);

void freeEnemyArray(Enemy ***enemyArray, int enemyCount);

void freeEnemy(Enemy **enemy);

void goToPlayer(Enemy *enemy, Position playerPosition);

#endif //CASTAWAY_ENEMY_H
