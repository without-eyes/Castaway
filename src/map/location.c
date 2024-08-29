#include "../../include/map/location.h"
#include "../../include/macros/tiles_macros.h"
#include "../../include/map/map.h"
#include <ncurses.h>
#include <stdlib.h>

Location setLocationData(const Position position) {
    Location location;
    location.position = position;
    location.tileSymbol = map[position.y][position.x];
    return location;
}

chtype getRandomWalkableTile(void) {
    int tile = rand() % 50;
    switch (tile) {
        case 0 ... 44:
            return PLAIN_GROUND_SYMBOL;
        case 45:
            return GRASS_SYMBOL_1;
        case 46:
            return GRASS_SYMBOL_2;
        case 47:
            return GRASS_SYMBOL_3;
        case 48:
            return GRASS_SYMBOL_4;
        case 49:
            return FLOWER_SYMBOL;
        default:
            break;
    }
}

bool isWalkableTile(chtype tileSymbol) {
    return tileSymbol == PLAIN_GROUND_SYMBOL ||
           tileSymbol == GRASS_SYMBOL_1 ||
           tileSymbol == GRASS_SYMBOL_2 ||
           tileSymbol == GRASS_SYMBOL_3 ||
           tileSymbol == GRASS_SYMBOL_4 ||
           tileSymbol == FLOWER_SYMBOL;
}