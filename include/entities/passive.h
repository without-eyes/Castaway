#ifndef CASTAWAY_PASSIVE_H
#define CASTAWAY_PASSIVE_H

#include "../stats/attributes.h"
#include "../map/location.h"

typedef struct {
    Location location;
    Attributes attributes;
} Passive;

Passive *initializePassive(Position position, int health, int damage, chtype symbol);

void createPassives(Passive ***passiveArray, int *passiveCount);

void removeDeadPassive(Passive ***passiveArray, int *passiveCount);

void freePassiveArray(Passive ***passiveArray, int passiveCount);

void freePassive(Passive **passive);

void idleAndMove(Passive *passive);

void randomMovement(Passive *passive);

#endif //CASTAWAY_PASSIVE_H
