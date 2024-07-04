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

void moveAllEntities(Player* player, Enemy** enemyArray, int enemyCount, Passive** passiveArray, int passiveCount) {
    for (int i = 0; i < enemyCount; i++) {
        goToPlayer(enemyArray[i], player);
    }

    for (int i = 0; i < passiveCount; i++) {
        randomMovement(passiveArray[i]);
    }
}
