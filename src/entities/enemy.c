#include <malloc.h>
#include <ncurses.h>
#include "../../include/entities/enemy.h"

Enemy* initialiseEnemy() {
    Enemy* enemy = (Enemy*)malloc(sizeof(Enemy));

    enemy->position.x = 10;
    enemy->position.y = 10;
    enemy->health = 10;
    enemy->health = 10;

    mvprintw(enemy->position.y, enemy->position.x, "E");

    return enemy;
}

void goToPlayer(Enemy* enemy, Player* player) {
    if (enemy->position.x < player->position.x) {
        moveEnemy(enemy->position.y, enemy->position.x + 1, enemy);
    } else if (enemy->position.x > player->position.x){
        moveEnemy(enemy->position.y, enemy->position.x - 1, enemy);
    }

    if (enemy->position.y < player->position.y) {
        moveEnemy(enemy->position.y + 1, enemy->position.x, enemy);
    } else if (enemy->position.y > player->position.y){
        moveEnemy(enemy->position.y - 1, enemy->position.x, enemy);
    }
}

void moveEnemy(const short y, const short x, Enemy* enemy) {
    if (mvinch(y, x) == '.') {
        mvprintw(enemy->position.y, enemy->position.x, ".");
        mvprintw(y, x, "E");
        move(y, x);
        enemy->position.y = y;
        enemy->position.x = x;
    }
}