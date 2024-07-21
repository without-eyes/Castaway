#include "../../include/entities/enemy.h"
#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include <ncurses.h>
#include <malloc.h>
#include <stdlib.h>

Enemy *initializeEnemy(const Position position, const int health, const int damage, const char symbol) {
    Enemy *enemy = (Enemy *) malloc(sizeof(Enemy));

    enemy->position = position;
    enemy->attributes = initializeEntity(health, damage, symbol);

    mvprintw(enemy->position.y, enemy->position.x, "%c", enemy->attributes.symbol);

    return enemy;
}

void createEnemies(Enemy ***enemyArray, int *enemyCount) {
    *enemyCount = rand() % (TEST_ENEMY_MAX_COUNT - TEST_ENEMY_MIN_COUNT) + TEST_ENEMY_MIN_COUNT;
    *enemyArray = (Enemy **) malloc(*enemyCount * sizeof(Enemy *));
    for (int i = 0; i < *enemyCount; i++) {
        (*enemyArray)[i] = initializeEnemy(getRandomPosition(), 15, 2, TEST_ENEMY_SYMBOL);
    }
}

void removeDeadEnemies(Enemy ***enemyArray, int* enemyCount) {
    for (int i = 0; i < *enemyCount; i++) {
        if ((*enemyArray)[i]->attributes.isAlive) {
            continue;
        }

        mvprintw((*enemyArray)[i]->position.y, (*enemyArray)[i]->position.x, "%c", TEST_DEAD_SYMBOL);

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
    if (enemy->position.x < playerPosition.x) {
        newPosition = (Position) {enemy->position.y, enemy->position.x + 1};
        moveEntity(newPosition, &enemy->position, enemy->attributes.symbol);
    } else if (enemy->position.x > playerPosition.x) {
        newPosition = (Position) {enemy->position.y, enemy->position.x - 1};
        moveEntity(newPosition, &enemy->position, enemy->attributes.symbol);
    }

    if (enemy->position.y < playerPosition.y) {
        newPosition = (Position) {enemy->position.y + 1, enemy->position.x};
        moveEntity(newPosition, &enemy->position, enemy->attributes.symbol);
    } else if (enemy->position.y > playerPosition.y) {
        newPosition = (Position) {enemy->position.y - 1, enemy->position.x};
        moveEntity(newPosition, &enemy->position, enemy->attributes.symbol);
    }
}