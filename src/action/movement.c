#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include <ncurses.h>

void moveEntity(const Position newPosition, Position *entityPosition, const char entitySymbol) {
    if (mvinch(newPosition.y, newPosition.x) == TEST_TILE_SYMBOL) {
        mvprintw(entityPosition->y, entityPosition->x, "%c", TEST_TILE_SYMBOL);
        mvprintw(newPosition.y, newPosition.x, "%c", entitySymbol);
        entityPosition->y = newPosition.y;
        entityPosition->x = newPosition.x;
    }
}

void moveAllEntities(Entities *entities) {
    for (int i = 0; i < entities->enemyCount; i++) {
        if (entities->enemyArray[i]->attributes.isAlive) {
            goToPlayer(entities->enemyArray[i], entities->player->position);
        }
    }

    for (int i = 0; i < entities->passiveCount; i++) {
        if (entities->passiveArray[i]->attributes.isAlive) {
            randomMovement(entities->passiveArray[i]);
        }
    }
}
