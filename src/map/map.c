#include "../../include/map/map.h"
#include "../../include/map/location.h"
#include "../../include/macros/tiles_macros.h"

chtype map[MAP_HEIGHT][MAP_WIDTH];

void createMap(void) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 ||
                j == 0 || j == MAP_WIDTH - 1) {
                map[i][j] = MOUNTAIN_INSIDE_SYMBOL;
            } else if (i == 1 || i == MAP_HEIGHT - 2 ||
                       j == 1 || j == MAP_WIDTH - 2) {
                map[i][j] = MOUNTAIN_OUTSIDE_SYMBOL;
            } else {
                map[i][j] = getRandomWalkableTile();
            }
        }
    }
}

void setCharOnMap(Position position, chtype symbol) {
    map[position.y][position.x] = symbol;
}
