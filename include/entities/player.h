#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "../core/movement.h"
#include "attributes.h"

typedef struct Player {
    Attributes attributes;
} Player;

Player *initialisePlayer();

void handleInput(unsigned char input, Player *player);

void movePlayer(short y, short x, Player *player);

#endif //CASTAWAY_PLAYER_H
