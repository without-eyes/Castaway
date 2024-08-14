#ifndef CASTAWAY_DRAW_H
#define CASTAWAY_DRAW_H

#include "../entities/player.h"

void setMap();

void playerDeathSituation(const Player* player);

void drawSymbol(Position position, chtype symbol);

void drawEntityMovement(Position newPosition, Position oldPosition, chtype tileSymbol, chtype entitySymbol);

void showHUD(const Player* player);

void initColors();

#endif //CASTAWAY_DRAW_H
