#include "../../include/entities/player.h"
#include "../../include/core/macros.h"
#include <malloc.h>
#include <ncurses.h>

Player *initialisePlayer(const Position position) {
    Player *player = (Player *) malloc(sizeof(Player));

    player->attributes = initializeEntity(position, 20, 2, PLAYER_SYMBOL);

    mvprintw(player->attributes.position.y, player->attributes.position.x, "%c", player->attributes.symbol);

    return player;
}