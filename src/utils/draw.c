#include "../../include/utils/draw.h"
#include "../../include/core/macros.h"
#include <ncurses.h>

void setMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 ||
                j == 0 || j == MAP_WIDTH - 1) {
                mvprintw(i, j, "%c", MOUNTAIN_OUTSIDE_SYMBOL);
            } else {
                mvprintw(i, j, "%c", getRandomWalkableTile());
            }
        }

        mvprintw(10, 10, "XXX");
        mvprintw(11, 10, "X.X");
        mvprintw(12, 10, "XXX");
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

void showHUD(const Player* player) {
    mvprintw(MAP_HEIGHT + 1, 0, "                           ");
    mvprintw(MAP_HEIGHT + 1, 0, "Health: %d  Position: %d %d", player->attributes.health, player->location.position.y, player->location.position.x);
}