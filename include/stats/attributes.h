#ifndef CASTAWAY_ATTRIBUTES_H
#define CASTAWAY_ATTRIBUTES_H

#include <stdbool.h>
#include <ncurses.h>
#include "position.h"

typedef struct {
    int health;
    int damage;
    chtype symbol;
} Attributes;

Attributes initializeAttributes(int health, int damage, chtype symbol);

bool isAlive(Attributes entityAttributes);

#endif //CASTAWAY_ATTRIBUTES_H
