#ifndef CASTAWAY_LOCATION_H
#define CASTAWAY_LOCATION_H

#include <ncurses.h>
#include "../stats/position.h"

typedef struct {
    Position position;
    chtype tileSymbol;
} Location;

Location initializeLocation(Position position);

chtype getRandomWalkableTile(void);

bool isTileWalkable(chtype tileSymbol);

#endif //CASTAWAY_LOCATION_H
