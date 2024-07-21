#ifndef CASTAWAY_POSITION_H
#define CASTAWAY_POSITION_H

#include <stdbool.h>

typedef struct {
    int y;
    int x;
} Position;

Position getRandomPosition();

bool arePositionsEqual(Position first, Position second);

bool areEntitiesBeside(Position first, Position second);

#endif //CASTAWAY_POSITION_H
