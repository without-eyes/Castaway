#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "../stats/attributes.h"

typedef struct {
    Position position;
    Attributes attributes;
} Player;

Player *initialisePlayer(Position position);

#endif //CASTAWAY_PLAYER_H
