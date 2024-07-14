#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

#include "../core/position.h"
#include "../core/attributes.h"
#include "passive.h"
#include "enemy.h"

typedef struct {
    Attributes attributes;
} Player;

Player *initialisePlayer(Position position);

void handleInput(char input, Player *player, Enemy **enemyArray, int enemyCount, Passive **passiveArray, int passiveCount);

#endif //CASTAWAY_PLAYER_H
