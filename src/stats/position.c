#include "../../include/stats/position.h"
#include "../../include/map/map.h"
#include "../../include/map/location.h"
#include <stdlib.h>

Position getRandomPosition(void) {
    Position position;
    do {
        position.y = rand() % MAP_HEIGHT;
        position.x = rand() % MAP_WIDTH;
    } while (!isTileWalkable(map[position.y][position.x]));
    return position;
}

inline bool arePositionsEqual(const Position first, const Position second) {
    return first.y == second.y && first.x == second.x;
}

inline bool areEntitiesBeside(const Position first, const Position second) {
    return (abs(first.y - second.y) + abs(first.x - second.x)) == 1;
}