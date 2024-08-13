#include "../../include/action/movement.h"
#include "../../include/utils/draw.h"
#include "../../include/core/macros.h"
#include <ncurses.h>
#include <string.h>

void moveEntity(const Position newPosition, Location *entityLocation, const char entitySymbol) {
    if (mvinch(newPosition.y, newPosition.x) == PLAIN_GROUND_SYMBOL ||
        mvinch(newPosition.y, newPosition.x) == GRASS_SYMBOL_1 ||
        mvinch(newPosition.y, newPosition.x) == GRASS_SYMBOL_2 ||
        mvinch(newPosition.y, newPosition.x) == GRASS_SYMBOL_3 ||
        mvinch(newPosition.y, newPosition.x) == GRASS_SYMBOL_4 ||
        mvinch(newPosition.y, newPosition.x) == FLOWER_SYMBOL) {
        char tileSymbol = mvinch(newPosition.y, newPosition.x);
        drawEntityMovement(newPosition, entityLocation->position, entityLocation->tileSymbol, entitySymbol);
        entityLocation->tileSymbol = tileSymbol;
        entityLocation->position.y = newPosition.y;
        entityLocation->position.x = newPosition.x;
    }

}
