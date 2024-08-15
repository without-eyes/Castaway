#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include "../../include/map/map.h"
#include <ncurses.h>

void moveEntity(const Position newPosition, Location *entityLocation, const chtype entitySymbol) {
    char tileSymbol = map[newPosition.y][newPosition.x];
    if (tileSymbol == PLAIN_GROUND_SYMBOL ||
        tileSymbol == GRASS_SYMBOL_1 ||
        tileSymbol == GRASS_SYMBOL_2 ||
        tileSymbol == GRASS_SYMBOL_3 ||
        tileSymbol == GRASS_SYMBOL_4 ||
        tileSymbol == FLOWER_SYMBOL) {
        setCharOnMap(entityLocation->position, entityLocation->tileSymbol);
        setCharOnMap(newPosition, entitySymbol);
        entityLocation->tileSymbol = tileSymbol;
        entityLocation->position.y = newPosition.y;
        entityLocation->position.x = newPosition.x;
    }

}
