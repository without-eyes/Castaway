#ifndef CASTAWAY_CASTAWAY_H
#define CASTAWAY_CASTAWAY_H

#include <ncurses.h>
#include "../entities/player.h"

void startGame(Player* player);
void initialiseScreen();
void setMap();
void endGame(Player* player);

#endif //CASTAWAY_CASTAWAY_H
