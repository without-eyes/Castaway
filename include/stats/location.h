#ifndef CASTAWAY_LOCATION_H
#define CASTAWAY_LOCATION_H

#include "position.h"

typedef struct {
    Position position;
    char tileSymbol;
} Location;

Location setLocationData(Position position);

char getRandomWalkableTile();

#endif //CASTAWAY_LOCATION_H
