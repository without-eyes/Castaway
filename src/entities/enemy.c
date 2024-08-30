#include "../../include/entities/enemy.h"
#include "../../include/action/movement.h"
#include "../../include/macros/test_macros.h"
#include "../../include/utils/draw.h"
#include <malloc.h>
#include <stdlib.h>

Enemy *initializeEnemy(const Position position, const int health, const int damage, const chtype symbol) {
    Enemy *enemy = (Enemy *) malloc(sizeof(Enemy));

    enemy->location = setLocationData(position);
    enemy->attributes = initializeAttributes(health, damage, symbol);

    drawSymbol(enemy->location.position, enemy->attributes.symbol);

    return enemy;
}

void initializeEnemyArray(Enemy ***enemyArray, int *enemyCount) {
    *enemyCount = rand() % (TEST_ENEMY_MAX_COUNT - TEST_ENEMY_MIN_COUNT) + TEST_ENEMY_MIN_COUNT;
    *enemyArray = (Enemy **) malloc(*enemyCount * sizeof(Enemy *));
    for (int i = 0; i < *enemyCount; i++) {
        (*enemyArray)[i] = initializeEnemy(getRandomPosition(), 10, 2, TEST_ENEMY_SYMBOL);
    }
}

void removeDeadEnemies(Enemy ***enemyArray, int *enemyCount) {
    for (int i = 0; i < *enemyCount; i++) {
        if (isAlive((*enemyArray)[i]->attributes)) {
            continue;
        }

        drawSymbol((*enemyArray)[i]->location.position, TEST_DEAD_SYMBOL);

        if (i < *enemyCount - 1) {
            (*enemyArray)[i] = (*enemyArray)[*enemyCount - 1];
        }

        (*enemyArray)[*enemyCount - 1] = NULL;
        (*enemyCount)--;
    }
}

void freeEnemyArray(Enemy ***enemyArray, const int enemyCount) {
    if (*enemyArray == NULL) {
        return;
    }

    for (int i = 0; i < enemyCount; i++) {
        if ((*enemyArray)[i]) {
            freeEnemy(&(*enemyArray)[i]);
        }
    }

    free(*enemyArray);
    *enemyArray = NULL;
}

void freeEnemy(Enemy **enemy) {
    if (*enemy == NULL) {
        return;
    }

    free(*enemy);
    *enemy = NULL;
}

void goToPlayer(Enemy *enemy, const Position playerPosition) {
    Position newPosition = enemy->location.position;

    if (newPosition.x < playerPosition.x) {
        newPosition.x++;
    } else if (newPosition.x > playerPosition.x) {
        newPosition.x--;
    }

    if (newPosition.y < playerPosition.y) {
        newPosition.y++;
    } else if (newPosition.y > playerPosition.y) {
        newPosition.y--;
    }

    moveEntity(newPosition, &enemy->location, enemy->attributes.symbol);
}