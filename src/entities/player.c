#include "../../include/entities/player.h"
#include "../../include/core/macros.h"
#include "../../include/core/draw.h"
#include <malloc.h>

Player *initializePlayer(const Position position) {
    Player *player = (Player *) malloc(sizeof(Player));

    player->position = position;
    player->attributes = initializeEntity(20, 2, PLAYER_SYMBOL);

    drawSymbol(player->position, player->attributes.symbol);

    return player;
}

void createPlayer(Player **player) {
    *player = initializePlayer(getRandomPosition());
}

void freePlayer(Player **player) {
    if (*player) {
        free(*player);
        *player = NULL;
    }
}