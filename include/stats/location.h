#ifndef CASTAWAY_LOCATION_H
#define CASTAWAY_LOCATION_H

#include <ncurses.h>
#include "position.h"

typedef struct {
    Position position;
    chtype tileSymbol;
} Location;

Location setLocationData(Position position);

chtype getRandomWalkableTile();

#endif //CASTAWAY_LOCATION_H
