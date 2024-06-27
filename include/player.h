#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "position.h"

typedef struct Player {
    Position position;
    short health;
    short damage;
} Player;

Player* initialisePlayer();
void handleInput(unsigned char input, Player* player);
void movePlayer(short y, short x, Player* player);

#endif //CASTAWAY_PLAYER_H
