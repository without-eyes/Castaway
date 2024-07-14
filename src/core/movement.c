#include "../../include/core/movement.h"

void moveEntity(const int y, const int x, Position *entityPosition, const char entitySymbol) {
    if (mvinch(y, x) == '.') {
        mvprintw(entityPosition->y, entityPosition->x, ".");
        mvprintw(y, x, "%c", entitySymbol);
        if (entitySymbol == '@') {
            move(y, x);
        }
        entityPosition->y = y;
        entityPosition->x = x;
    }
}

void moveAllEntities(Player *player, Enemy **enemyArray, int enemyCount, Passive **passiveArray, int passiveCount) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemyArray[i]->attributes.isAlive) {
            goToPlayer(enemyArray[i], player->attributes.position);
        }
    }

    for (int i = 0; i < passiveCount; i++) {
        if (passiveArray[i]->attributes.isAlive) {
            randomMovement(passiveArray[i]);
        }
    }
}
