#include "../../include/utils/draw.h"
#include "../../include/core/macros.h"
#include "../../include/map/map.h"
#include <ncurses.h>

void playerDeathSituation(const Player *player) {
    if (!player->attributes.isAlive) {
        clear();
        attron(COLOR_PAIR(6));
        mvprintw(1, 1, "YOU ARE DEAD!");
        attroff(COLOR_PAIR(6));
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

    map[position.y][position.x] = symbol;

    attron(COLOR_PAIR(pairNumber));
    mvprintw(position.y, position.x, "%c", symbol);
    attroff(COLOR_PAIR(pairNumber));

}

void showHUD(const Player *player) {
    mvprintw(MAP_HEIGHT + 1, 0, "                           ");
    mvprintw(MAP_HEIGHT + 1, 0, "Health: %d  Position: %d %d", player->attributes.health, player->location.position.y,
             player->location.position.x);
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

void drawMapAroundPlayer(const Player *player) {
    clear();

    int screenStartY = player->location.position.y - SCREEN_HEIGHT / 2;
    int screenStartX = player->location.position.x - SCREEN_WIDTH / 2;

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            int mapY = screenStartY + i;
            int mapX = screenStartX + j;
            Position position = {i, j};

            if (mapY >= 0 && mapY < MAP_HEIGHT && mapX >= 0 && mapX < MAP_WIDTH) {
                drawSymbol(position, map[mapY][mapX]);
            } else {
                drawSymbol(position, ' ');
            }
        }
    }

    drawSymbol((Position){SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2}, player->attributes.symbol);
}

