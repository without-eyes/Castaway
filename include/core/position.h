#ifndef CASTAWAY_POSITION_H
#define CASTAWAY_POSITION_H

#include <ncurses.h>

typedef struct {
    int y;
    int x;
} Position;

Position getRandomPosition();

#endif //CASTAWAY_POSITION_H
