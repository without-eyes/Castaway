#include "../../include/stats/position.h"
#include "../../include/core/macros.h"
#include <ncurses.h>
#include <stdlib.h>

Position getRandomPosition() {
    Position position;
    do {
        position.y = rand() % MAP_HEIGHT;
        position.x = rand() % MAP_WIDTH;
    } while (mvinch(position.y, position.x) != TEST_TILE_SYMBOL);
    return position;
}

bool arePositionsEqual(Position first, Position second) {
    return first.y == second.y && first.x == second.x;
}

bool areEntitiesBeside(const Position first, const Position second) {
    return (abs(first.y - second.y) + abs(first.x - second.x)) == 1;
}