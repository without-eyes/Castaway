#ifndef CASTAWAY_DRAW_H
#define CASTAWAY_DRAW_H

#include "../entities/player.h"

void playerDeathSituation(const Player *player);

void drawSymbol(Position position, chtype symbol);

void drawEntityMovement(Position newPosition, Position oldPosition, chtype tileSymbol, chtype entitySymbol);

void showHUD(const Player *player);

void initColors();

void drawMapAroundPlayer(const Player *player);

#endif //CASTAWAY_DRAW_H
