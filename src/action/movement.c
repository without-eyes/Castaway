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
