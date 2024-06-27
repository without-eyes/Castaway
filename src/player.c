#include "../include/player.h"

#include "../include/castaway.h"
#include <malloc.h>

Player* initialisePlayer() {
    Player * player = (Player*)malloc(sizeof(Player));
    player->x = 0;
    player->y = 0;
    player->health = 100;
    player->damage = 5;

    mvprintw(player->y, player->x, "@");
    move(player->y, player->x);

    return player;
}

void handleInput(const unsigned char input, const Player* player) {
    switch (input) {
        case 'W':
        case 'w':
            movePlayer(player->y - 1, player->x, player);
            break;

        case 'A':
        case 'a':
            movePlayer(player->y, player->x - 1, player);
            break;

        case 'S':
        case 's':
            movePlayer(player->y + 1, player->x, player);
            break;

        case 'D':
        case 'd':
            movePlayer(player->y, player->x + 1, player);
            break;

        default: break;
    }
}

void movePlayer(const short y, const short x, Player* player) {
    if (mvinch(y, x) == '.') {
        mvprintw(player->y, player->x, ".");
        mvprintw(y, x, "@");
        move(y, x);
        player->y = y;
        player->x = x;
    }
}