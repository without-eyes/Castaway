#include "../include/player.h"

#include "../include/castaway.h"
#include <malloc.h>

Player* initialisePlayer() {
    Player * player = (Player*)malloc(sizeof(Player));
    player->position.x = 0;
    player->position.y = 0;
    player->health = 100;
    player->damage = 5;

    mvprintw(player->position.y, player->position.x, "@");
    move(player->position.y, player->position.x);

    return player;
}

void handleInput(const unsigned char input, Player* player) {
    switch (input) {
        case 'W':
        case 'w':
            movePlayer(player->position.y - 1, player->position.x, player);
            break;

        case 'A':
        case 'a':
            movePlayer(player->position.y, player->position.x - 1, player);
            break;

        case 'S':
        case 's':
            movePlayer(player->position.y + 1, player->position.x, player);
            break;

        case 'D':
        case 'd':
            movePlayer(player->position.y, player->position.x + 1, player);
            break;

        default: break;
    }
}

void movePlayer(const short y, const short x, Player* player) {
    if (mvinch(y, x) == '.') {
        mvprintw(player->position.y, player->position.x, ".");
        mvprintw(y, x, "@");
        move(y, x);
        player->position.y = y;
        player->position.x = x;
    }
}