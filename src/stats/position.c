#include "../../include/stats/position.h"
#include "../../include/macros/tiles_macros.h"
#include "../../include/map/map.h"
#include <stdlib.h>

Position getRandomPosition(void) {
    Position position;
    do {
        position.y = rand() % MAP_HEIGHT;
        position.x = rand() % MAP_WIDTH;
    } while (map[position.y][position.x] == MOUNTAIN_INSIDE_SYMBOL ||
            map[position.y][position.x] == MOUNTAIN_OUTSIDE_SYMBOL);
    return position;
}

bool arePositionsEqual(Position first, Position second) {
    return first.y == second.y && first.x == second.x;
}

bool areEntitiesBeside(const Position first, const Position second) {
    return (abs(first.y - second.y) + abs(first.x - second.x)) == 1;
}