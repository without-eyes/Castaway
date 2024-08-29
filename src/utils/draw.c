#include "../../include/utils/draw.h"
#include "../../include/macros/entity_macros.h"
#include "../../include/macros/test_macros.h"
#include "../../include/macros/tiles_macros.h"
#include "../../include/map/map.h"
#include <ncurses.h>

void playerDeathSituation(const Player *player) {
    if (!isAlive(player->attributes)) {
        clear();
        attron(COLOR_PAIR(6));
        mvprintw(1, 1, "YOU ARE DEAD!");
        attroff(COLOR_PAIR(6));
        mvprintw(5, 1, "Press any button to continue...");
        getch();
    }
}

void drawSymbol(const Position position, const chtype symbol) {
    short colorPair;
    switch (symbol & A_CHARTEXT) {
        // BLACK
        case PLAIN_GROUND_SYMBOL:
            colorPair = BLACK_ON_BLACK;
            break;

        // GREEN
        case GRASS_SYMBOL_1:
        case GRASS_SYMBOL_2:
        case GRASS_SYMBOL_3:
        case GRASS_SYMBOL_4:
            colorPair = GREEN_ON_BLACK;
            break;

        // MAGENTA
        case FLOWER_SYMBOL:
            colorPair = MAGENTA_ON_BLACK;
            break;

        // GREY
        case MOUNTAIN_OUTSIDE_SYMBOL:
            colorPair = GREY_ON_BLACK;
            break;

        // WHITE
        case PLAYER_SYMBOL:
        case MOUNTAIN_INSIDE_SYMBOL:
            colorPair = WHITE_ON_BLACK;
            break;

        // RED
        case TEST_DEAD_SYMBOL:
        case TEST_ENEMY_SYMBOL:
            colorPair = RED_ON_BLACK;
            break;

        // YELLOW
        case TEST_PASSIVE_SYMBOL:
            colorPair = YELLOW_ON_BLACK;
            break;

        // CYAN
        default:
            colorPair = CYAN_ON_BLACK;
            break;
    }

    map[position.y][position.x] = symbol;

    attron(COLOR_PAIR(colorPair));
    mvprintw(position.y, position.x, "%c", symbol);
    attroff(COLOR_PAIR(colorPair));

}

void showHUD(const Player *player) {
    mvprintw(MAP_HEIGHT + 1, 0, "                           ");
    mvprintw(MAP_HEIGHT + 1, 0, "Health: %d  Position: %d %d", player->attributes.health, player->location.position.y,
             player->location.position.x);
}

void initColors(void) {
    if (has_colors()) {
        start_color();
    }

    init_color(8, 232, 232, 232); // grey

    short backgroundColor = COLOR_BLACK;
    init_pair(BLACK_ON_BLACK, COLOR_BLACK, backgroundColor);
    init_pair(GREEN_ON_BLACK, COLOR_GREEN, backgroundColor);
    init_pair(MAGENTA_ON_BLACK, COLOR_MAGENTA, backgroundColor);
    init_pair(GREY_ON_BLACK, 8, backgroundColor);
    init_pair(WHITE_ON_BLACK, COLOR_WHITE, backgroundColor);
    init_pair(RED_ON_BLACK, COLOR_RED, backgroundColor);
    init_pair(YELLOW_ON_BLACK, COLOR_YELLOW, backgroundColor);
    init_pair(CYAN_ON_BLACK, COLOR_CYAN, backgroundColor);
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

void drawFrame(Entities *entities) {
    drawMapAroundPlayer(entities->player);
    showHUD(entities->player);
}