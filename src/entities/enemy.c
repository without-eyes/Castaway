#include <malloc.h>
#include "../../include/entities/enemy.h"

Enemy *initialiseEnemy() {
    Enemy *enemy = (Enemy *) malloc(sizeof(Enemy));

    enemy->attributes = initializeEntity((Position) {10, 10}, 10, 10, 'E');

    mvprintw(enemy->attributes.position.y, enemy->attributes.position.x, "%c", enemy->attributes.symbol);

    return enemy;
}

void goToPlayer(Enemy *enemy, Player *player) {
    if (enemy->attributes.position.x < player->attributes.position.x) {
        moveEntity(enemy->attributes.position.y, enemy->attributes.position.x + 1, &enemy->attributes.position,
                   enemy->attributes.symbol);
    } else if (enemy->attributes.position.x > player->attributes.position.x) {
        moveEntity(enemy->attributes.position.y, enemy->attributes.position.x - 1, &enemy->attributes.position,
                   enemy->attributes.symbol);
    }

    if (enemy->attributes.position.y < player->attributes.position.y) {
        moveEntity(enemy->attributes.position.y + 1, enemy->attributes.position.x, &enemy->attributes.position,
                   enemy->attributes.symbol);
    } else if (enemy->attributes.position.y > player->attributes.position.y) {
        moveEntity(enemy->attributes.position.y - 1, enemy->attributes.position.x, &enemy->attributes.position,
                   enemy->attributes.symbol);
    }
}