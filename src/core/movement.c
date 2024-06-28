#include "../../include/core/movement.h"

void moveEntity(const short y, const short x, Position* entityPosition, const char entitySymbol) {
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