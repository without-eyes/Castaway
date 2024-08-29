#include "../../include/action/movement.h"
#include "../../include/map/map.h"
#include <ncurses.h>

void moveEntity(const Position newPosition, Location *entityLocation, const chtype entitySymbol) {
    chtype tileSymbol = map[newPosition.y][newPosition.x];
    if (isWalkableTile(tileSymbol)) {
        setCharOnMap(entityLocation->position, entityLocation->tileSymbol);
        setCharOnMap(newPosition, entitySymbol);
        entityLocation->tileSymbol = tileSymbol;
        entityLocation->position = newPosition;
    }
}
