#ifndef CASTAWAY_ATTRIBUTES_H
#define CASTAWAY_ATTRIBUTES_H

#include "../core/movement.h"

typedef struct Attributes {
    Position position;
    short health;
    short damage;
    char symbol;
} Attributes;

Attributes initialiseEntity(Position position, short health, short damage, char symbol);

#endif //CASTAWAY_ATTRIBUTES_H
