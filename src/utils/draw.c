#include "../../include/utils/draw.h"
#include "../../include/core/macros.h"
#include <ncurses.h>

void setMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            Position position = {i, j};
            if (i == 0 || i == MAP_HEIGHT - 1 ||
                j == 0 || j == MAP_WIDTH - 1) {
                drawSymbol(position, MOUNTAIN_INSIDE_SYMBOL);
            } else if (i == 1 || i == MAP_HEIGHT - 2 ||
                       j == 1 || j == MAP_WIDTH - 2) {
                drawSymbol(position, MOUNTAIN_OUTSIDE_SYMBOL);
            } else {
                drawSymbol(position, getRandomWalkableTile());
            }
        }
    }
    refresh();
}

void playerDeathSituation(const Player* player) {
    if (!player->attributes.isAlive) {
        clear();
        mvprintw(1, 1, "YOU ARE DEAD!");
        mvprintw(5, 1, "Press any button to continue...");
        getch();
    }
}

void drawSymbol(const Position position, const chtype symbol) {
    short pairNumber;
    switch (symbol & A_CHARTEXT) {
        // BLACK
        case PLAIN_GROUND_SYMBOL:
            pairNumber = 1;
            break;

        // GREEN
        case GRASS_SYMBOL_1:
        case GRASS_SYMBOL_2:
        case GRASS_SYMBOL_3:
        case GRASS_SYMBOL_4:
            pairNumber = 2;
            break;

        // MAGENTA
        case FLOWER_SYMBOL:
            pairNumber = 3;
            break;

        // GREY
        case MOUNTAIN_OUTSIDE_SYMBOL:
            pairNumber = 4;
            break;

        // WHITE
        case PLAYER_SYMBOL:
        case MOUNTAIN_INSIDE_SYMBOL:
            pairNumber = 5;
            break;

        // RED
        case TEST_DEAD_SYMBOL:
        case TEST_ENEMY_SYMBOL:
            pairNumber = 6;
            break;

        // YELLOW
        case TEST_PASSIVE_SYMBOL:
            pairNumber = 7;
            break;

        // CYAN
        default:
            pairNumber = 8;
            break;
    }

    attron(COLOR_PAIR(pairNumber));
    mvprintw(position.y, position.x, "%c", symbol);
    attroff(COLOR_PAIR(pairNumber));
}

void drawEntityMovement(const Position newPosition, const Position oldPosition, const chtype tileSymbol, const chtype entitySymbol) {
    drawSymbol(oldPosition, tileSymbol);
    drawSymbol(newPosition, entitySymbol);
}

void showHUD(const Player* player) {
    mvprintw(MAP_HEIGHT + 1, 0, "                           ");
    mvprintw(MAP_HEIGHT + 1, 0, "Health: %d  Position: %d %d", player->attributes.health, player->location.position.y, player->location.position.x);
}

void initColors() {
    if (has_colors()) {
        start_color();
    }

    init_color(8, 232, 232, 232); // grey

    short backgroundColor = COLOR_BLACK;
    init_pair(1, COLOR_BLACK, backgroundColor);
    init_pair(2, COLOR_GREEN, backgroundColor);
    init_pair(3, COLOR_MAGENTA, backgroundColor);
    init_pair(4, 8, backgroundColor);
    init_pair(5, COLOR_WHITE, backgroundColor);
    init_pair(6, COLOR_RED, backgroundColor);
    init_pair(7, COLOR_YELLOW, backgroundColor);
    init_pair(8, COLOR_CYAN, backgroundColor);
}