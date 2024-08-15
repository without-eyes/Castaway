#include "../../include/entities/enemy.h"
#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include "../../include/utils/draw.h"
#include <malloc.h>
#include <stdlib.h>

Enemy *initializeEnemy(const Position position, const int health, const int damage, const chtype symbol) {
    Enemy *enemy = (Enemy *) malloc(sizeof(Enemy));

    enemy->location = setLocationData(position);
    enemy->attributes = initializeEntity(health, damage, symbol);

    drawSymbol(enemy->location.position, enemy->attributes.symbol);

    return enemy;
}

void createEnemies(Enemy ***enemyArray, int *enemyCount) {
    *enemyCount = rand() % (TEST_ENEMY_MAX_COUNT - TEST_ENEMY_MIN_COUNT) + TEST_ENEMY_MIN_COUNT;
    *enemyArray = (Enemy **) malloc(*enemyCount * sizeof(Enemy *));
    for (int i = 0; i < *enemyCount; i++) {
        (*enemyArray)[i] = initializeEnemy(getRandomPosition(), 10, 2, TEST_ENEMY_SYMBOL);
    }
}

void removeDeadEnemies(Enemy ***enemyArray, int *enemyCount) {
    for (int i = 0; i < *enemyCount; i++) {
        if ((*enemyArray)[i]->attributes.isAlive) {
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

void freeEnemies(Enemy ***enemyArray, const int enemyCount) {
    if (*enemyArray) {
        for (int i = 0; i < enemyCount; i++) {
            if ((*enemyArray)[i]) {
                freeEnemy(&(*enemyArray)[i]);
            }
        }
        free(*enemyArray);
        *enemyArray = NULL;
    }
}

void freeEnemy(Enemy **enemy) {
    if (*enemy) {
        free(*enemy);
        *enemy = NULL;
    }
}

void goToPlayer(Enemy *enemy, const Position playerPosition) {
    Position newPosition;
    if (enemy->location.position.x < playerPosition.x) {
        newPosition = (Position) {enemy->location.position.y, enemy->location.position.x + 1};
        moveEntity(newPosition, &enemy->location, enemy->attributes.symbol);
    } else if (enemy->location.position.x > playerPosition.x) {
        newPosition = (Position) {enemy->location.position.y, enemy->location.position.x - 1};
        moveEntity(newPosition, &enemy->location, enemy->attributes.symbol);
    }

    if (enemy->location.position.y < playerPosition.y) {
        newPosition = (Position) {enemy->location.position.y + 1, enemy->location.position.x};
        moveEntity(newPosition, &enemy->location, enemy->attributes.symbol);
    } else if (enemy->location.position.y > playerPosition.y) {
        newPosition = (Position) {enemy->location.position.y - 1, enemy->location.position.x};
        moveEntity(newPosition, &enemy->location, enemy->attributes.symbol);
    }
}