#ifndef CASTAWAY_ATTRIBUTES_H
#define CASTAWAY_ATTRIBUTES_H

#include <stdbool.h>
#include "position.h"

typedef struct {
    int health;
    int damage;
    char symbol;
    bool isAlive;
} Attributes;

Attributes initializeEntity(int health, int damage, char symbol);


#endif //CASTAWAY_ATTRIBUTES_H
