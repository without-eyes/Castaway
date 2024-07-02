#include <stdlib.h>
#include "../../include/core/position.h"

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

Position getRandomPosition() {
    int y;
    int x;
    do {
        y = rand() % 40;
        x = rand() % 70;
    } while (mvinch(y, x) != '.');
    return (Position){y, x};
};