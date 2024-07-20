#ifndef CASTAWAY_PASSIVE_H
#define CASTAWAY_PASSIVE_H

#include "../stats/attributes.h"

typedef struct {
    Position position;
    Attributes attributes;
} Passive;

Passive *initializePassive(Position position, int health, int damage, char symbol);

void idleAndMove(Passive *passive);

void randomMovement(Passive *passive);

#endif //CASTAWAY_PASSIVE_H
