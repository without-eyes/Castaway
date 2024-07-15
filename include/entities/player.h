#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "../core/attributes.h"

typedef struct {
    Attributes attributes;
} Player;

Player *initialisePlayer(Position position);

#endif //CASTAWAY_PLAYER_H
