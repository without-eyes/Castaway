#ifndef CASTAWAY_DRAW_H
#define CASTAWAY_DRAW_H

#include "../entities/player.h"
#include "../entities/entities.h"

enum ColorPairs {
    BLACK_ON_BLACK = 1,
    GREEN_ON_BLACK,
    MAGENTA_ON_BLACK,
    GREY_ON_BLACK,
    WHITE_ON_BLACK,
    RED_ON_BLACK,
    YELLOW_ON_BLACK,
    CYAN_ON_BLACK,
};

void showDeathScreen(const Player *player);

void drawSymbol(Position position, chtype symbol);

void drawEntityMovement(Position newPosition, Position oldPosition, chtype tileSymbol, chtype entitySymbol);

void showHUD(const Player *player);

void initColors(void);

void drawFrame(const Entities *entities);

void drawMapAroundPlayer(const Player *player);

#endif //CASTAWAY_DRAW_H
