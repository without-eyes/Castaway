#ifndef CASTAWAY_CASTAWAY_H
#define CASTAWAY_CASTAWAY_H

#include "../entities/entities.h"

void runGame(void);

void startGame(Entities **entities);

void setScreenAttributes(void);

void gameLoop(Entities *entities);

void endGame(Entities **entities);

#endif //CASTAWAY_CASTAWAY_H
