#include "../../include/entities/player.h"
#include "../../include/core/castaway.h"
#include "../../include/core/movement.h"
#include "../../include/core/combat.h"
#include <malloc.h>

Player *initialisePlayer(Position position) {
    Player *player = (Player *) malloc(sizeof(Player));
    player->attributes = initializeEntity(position, 20, 2, '@');

    mvprintw(player->attributes.position.y, player->attributes.position.x, "%c", player->attributes.symbol);

    return player;
}

void handleInput(const char input, Player *player, Enemy **enemyArray, int enemyCount, Passive **passiveArray, int passiveCount) {
    int newY, newX;
    switch (input) {
        case 'W':
        case 'w':
            newY = player->attributes.position.y - 1;
            newX = player->attributes.position.x;
            if (mvinch(newY, newX) == 'E') {
                combatEnemy(player, findAttackedEnemy(enemyArray, enemyCount, newY, newX), true);
            } else if (mvinch(newY, newX) == 'P') {
                combatPassive(player, findAttackedPassive(passiveArray, passiveCount, newY, newX));
            } else {
                moveEntity(newY, newX, &player->attributes.position,player->attributes.symbol);
            }
            break;

        case 'A':
        case 'a':
            newY = player->attributes.position.y;
            newX = player->attributes.position.x - 1;
            if (mvinch(newY, newX) == 'E') {
                combatEnemy(player, findAttackedEnemy(enemyArray, enemyCount, newY, newX), true);
            } else if (mvinch(newY, newX) == 'P') {
                combatPassive(player, findAttackedPassive(passiveArray, passiveCount, newY, newX));
            } else {
                moveEntity(newY, newX, &player->attributes.position,player->attributes.symbol);
            }
            break;

        case 'S':
        case 's':
            newY = player->attributes.position.y + 1;
            newX = player->attributes.position.x;
            if (mvinch(newY, newX) == 'E') {
                combatEnemy(player, findAttackedEnemy(enemyArray, enemyCount, newY, newX), true);
            } else if (mvinch(newY, newX) == 'P') {
                combatPassive(player, findAttackedPassive(passiveArray, passiveCount, newY, newX));
            } else {
                moveEntity(newY, newX, &player->attributes.position,player->attributes.symbol);
            }
            break;

        case 'D':
        case 'd':
            newY = player->attributes.position.y;
            newX = player->attributes.position.x + 1;
            if (mvinch(newY, newX) == 'E') {
                combatEnemy(player, findAttackedEnemy(enemyArray, enemyCount, newY, newX), true);
            } else if (mvinch(newY, newX) == 'P') {
                combatPassive(player, findAttackedPassive(passiveArray, passiveCount, newY, newX));
            } else {
                moveEntity(newY, newX, &player->attributes.position,player->attributes.symbol);
            }
            break;

        default:
            break;
    }
}