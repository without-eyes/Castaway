#ifndef CASTAWAY_LOCATION_H
#define CASTAWAY_LOCATION_H

#include <ncurses.h>
#include "../stats/position.h"

typedef struct {
    Position position;
    chtype tileSymbol;
} Location;

Location setLocationData(Position position);

chtype getRandomWalkableTile(void);

bool isWalkableTile(chtype tileSymbol);

#endif //CASTAWAY_LOCATION_H
