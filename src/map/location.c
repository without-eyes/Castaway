#include "../../include/map/location.h"
#include "../../include/macros/tiles_macros.h"
#include "../../include/map/map.h"
#include <ncurses.h>
#include <stdlib.h>

Location initializeLocation(const Position position) {
    Location location;
    location.position = position;
    location.tileSymbol = map[position.y][position.x];
    return location;
}

chtype getRandomWalkableTile(void) {
    const int randValue = rand() % 50;

    if (randValue >= 0 && randValue <= 44) {
        return PLAIN_GROUND_SYMBOL;
    } else if (randValue == 45) {
        return GRASS_SYMBOL_1;
    } else if (randValue == 46) {
        return GRASS_SYMBOL_2;
    } else if (randValue == 47) {
        return GRASS_SYMBOL_3;
    } else if (randValue == 48) {
        return GRASS_SYMBOL_4;
    } else {
        return FLOWER_SYMBOL;
    }
}

bool isTileWalkable(const chtype tileSymbol) {
    return tileSymbol == PLAIN_GROUND_SYMBOL ||
           tileSymbol == GRASS_SYMBOL_1 ||
           tileSymbol == GRASS_SYMBOL_2 ||
           tileSymbol == GRASS_SYMBOL_3 ||
           tileSymbol == GRASS_SYMBOL_4 ||
           tileSymbol == FLOWER_SYMBOL;
}