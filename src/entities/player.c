#include "../../include/entities/player.h"
#include "../../include/core/macros.h"
#include <malloc.h>
#include <ncurses.h>

Player *initialisePlayer(const Position position) {
    Player *player = (Player *) malloc(sizeof(Player));

    player->position = position;
    player->attributes = initializeEntity(20, 2, PLAYER_SYMBOL);

    mvprintw(player->position.y, player->position.x, "%c", player->attributes.symbol);

    return player;
}