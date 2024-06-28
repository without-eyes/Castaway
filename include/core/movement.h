#ifndef CASTAWAY_MOVEMENT_H
#define CASTAWAY_MOVEMENT_H

#include <ncurses.h>

typedef struct Position {
    short x;
    short y;
} Position;

void moveEntity(short y, short x, Position* entityPosition, char entitySymbol);

#endif //CASTAWAY_MOVEMENT_H
