#ifndef CASTAWAY_ATTRIBUTES_H
#define CASTAWAY_ATTRIBUTES_H

#include <stdbool.h>
#include <ncurses.h>
#include "position.h"

typedef struct {
    int health;
    int damage;
    chtype symbol;
    bool isAlive;
} Attributes;

Attributes initializeEntity(int health, int damage, chtype symbol);


#endif //CASTAWAY_ATTRIBUTES_H
