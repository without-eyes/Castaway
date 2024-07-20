#include "../../include/entities/enemy.h"
#include "../../include/action/movement.h"
#include <ncurses.h>
#include <malloc.h>

Enemy *initializeEnemy(const Position position, const int health, const int damage, const char symbol) {
    Enemy *enemy = (Enemy *) malloc(sizeof(Enemy));

    enemy->position = position;
    enemy->attributes = initializeEntity(health, damage, symbol);

    mvprintw(enemy->position.y, enemy->position.x, "%c", enemy->attributes.symbol);

    return enemy;
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