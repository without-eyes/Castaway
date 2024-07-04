#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "../core/position.h"
#include "../core/attributes.h"

typedef struct {
    Attributes attributes;
} Player;

Player *initialisePlayer(Position position);

void handleInput(char input, Player *player);

void movePlayer(int y, int x, Player *player);

#endif //CASTAWAY_PLAYER_H
