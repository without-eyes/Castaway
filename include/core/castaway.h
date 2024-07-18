#ifndef CASTAWAY_CASTAWAY_H
#define CASTAWAY_CASTAWAY_H

#include "../entities/entities.h"

void runGame();

void startGame();

void initializeScreen();

void setMap();

void gameLoop(Entities *entities);

void endGame();

#endif //CASTAWAY_CASTAWAY_H
