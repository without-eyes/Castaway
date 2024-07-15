#include "../../include/entities/enemy.h"
#include "../../include/core/movement.h"
#include <ncurses.h>
#include <malloc.h>

Enemy *initialiseEnemy(const Position position, const int health, const int damage, const char symbol) {
    Enemy *enemy = (Enemy *) malloc(sizeof(Enemy));

    enemy->attributes = initializeEntity(position, health, damage, symbol);

    mvprintw(enemy->attributes.position.y, enemy->attributes.position.x, "%c", enemy->attributes.symbol);

    return enemy;
}

void goToPlayer(Enemy *enemy, const Position playerPosition) {
    Position newPosition;
    if (enemy->attributes.position.x < playerPosition.x) {
        newPosition = (Position) {enemy->attributes.position.y, enemy->attributes.position.x + 1};
        moveEntity(newPosition, &enemy->attributes.position, enemy->attributes.symbol);
    } else if (enemy->attributes.position.x > playerPosition.x) {
        newPosition = (Position) {enemy->attributes.position.y, enemy->attributes.position.x - 1};
        moveEntity(newPosition, &enemy->attributes.position, enemy->attributes.symbol);
    }

    if (enemy->attributes.position.y < playerPosition.y) {
        newPosition = (Position) {enemy->attributes.position.y + 1, enemy->attributes.position.x};
        moveEntity(newPosition, &enemy->attributes.position, enemy->attributes.symbol);
    } else if (enemy->attributes.position.y > playerPosition.y) {
        newPosition = (Position) {enemy->attributes.position.y - 1, enemy->attributes.position.x};
        moveEntity(newPosition, &enemy->attributes.position, enemy->attributes.symbol);
    }
}