#include "../../include/entities/player.h"
#include "../../include/macros/entity_macros.h"
#include "../../include/utils/draw.h"
#include <malloc.h>

Player *initializePlayer(const Position position) {
    Player *player = (Player *) malloc(sizeof(Player));

    player->location = setLocationData(position);
    player->attributes = initializeAttributes(20, 2, PLAYER_SYMBOL);

    drawSymbol(player->location.position, player->attributes.symbol);

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