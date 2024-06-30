#ifndef CASTAWAY_PASSIVE_H
#define CASTAWAY_PASSIVE_H

#include "attributes.h"

typedef struct Passive {
    Attributes attributes;
} Passive;

Passive *initialisePassive();

void randomMovement(Passive *passive);

#endif //CASTAWAY_PASSIVE_H
