#include "../../include/core/draw.h"
#include "../../include/core/macros.h"
#include <ncurses.h>

void setMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            mvprintw(i, j, ".");
        }
    }
}

void playerDeathSituation(const Player* player) {
    if (!player->attributes.isAlive) {
        clear();
        mvprintw(1, 1, "YOU ARE DEAD!");
        mvprintw(5, 1, "Press any button to continue...");
        getch();
    }
}

void drawSymbol(const Position position, const char symbol) {
    mvprintw(position.y, position.x, "%c", symbol);
}

void drawEntityMovement(const Position newPosition, const Position oldPosition, const char tileSymbol, const char entitySymbol) {
    mvprintw(oldPosition.y, oldPosition.x, "%c", tileSymbol);
    mvprintw(newPosition.y, newPosition.x, "%c", entitySymbol);
}