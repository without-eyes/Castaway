#include "../../include/entities/player.h"

#include "../../include/core/castaway.h"
#include <malloc.h>

Player* initialisePlayer() {
    Player * player = (Player*)malloc(sizeof(Player));
    player->attributes = initializeEntity((Position){0, 0}, 10, 10, '@');

    mvprintw(player->attributes.position.y, player->attributes.position.x, "%c", player->attributes.symbol);

    return player;
}

void handleInput(const unsigned char input, Player* player) {
    switch (input) {
        case 'W':
        case 'w':
            moveEntity(player->attributes.position.y - 1, player->attributes.position.x, &player->attributes.position, player->attributes.symbol);
            break;

        case 'A':
        case 'a':
            moveEntity(player->attributes.position.y, player->attributes.position.x - 1, &player->attributes.position, player->attributes.symbol);
            break;

        case 'S':
        case 's':
            moveEntity(player->attributes.position.y + 1, player->attributes.position.x, &player->attributes.position, player->attributes.symbol);
            break;

        case 'D':
        case 'd':
            moveEntity(player->attributes.position.y, player->attributes.position.x + 1, &player->attributes.position, player->attributes.symbol);
            break;

        default: break;
    }
}