#ifndef CASTAWAY_MAP_H
#define CASTAWAY_MAP_H

#include <ncurses.h>
#include "../macros/screen_macros.h"
#include "../stats/position.h"

// ===== GLOBAL VARIABLE =====

extern chtype map[MAP_HEIGHT][MAP_WIDTH];

// ===========================

void createMap(void);

void setCharOnMap(Position position, chtype symbol);

#endif //CASTAWAY_MAP_H
