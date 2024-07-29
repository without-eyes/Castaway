#ifndef CASTAWAY_DRAW_H
#define CASTAWAY_DRAW_H

#include "../entities/player.h"

void setMap();

void playerDeathSituation(const Player* player);

void drawSymbol(Position position, char symbol);

void drawEntityMovement(Position newPosition, Position oldPosition, char tileSymbol, char entitySymbol);

#endif //CASTAWAY_DRAW_H
