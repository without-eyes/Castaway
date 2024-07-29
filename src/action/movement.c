#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include "../../include/core/draw.h"
#include <ncurses.h>

void moveEntity(const Position newPosition, Position *entityPosition, const char entitySymbol) {
    if (mvinch(newPosition.y, newPosition.x) == TEST_TILE_SYMBOL) {
        drawEntityMovement(newPosition, *entityPosition, TEST_TILE_SYMBOL, entitySymbol);
        entityPosition->y = newPosition.y;
        entityPosition->x = newPosition.x;
    }
}
