#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "../stats/attributes.h"

typedef struct {
    Position position;
    Attributes attributes;
} Player;

Player *initializePlayer(Position position);

void createPlayer(Player **player);

void freePlayer(Player **player);

#endif //CASTAWAY_PLAYER_H
