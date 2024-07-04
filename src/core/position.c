#include <stdlib.h>
#include "../../include/core/position.h"

Position getRandomPosition() {
    int y;
    int x;
    do {
        y = rand() % 40;
        x = rand() % 70;
    } while (mvinch(y, x) != '.');
    return (Position){y, x};
};