#include "../../include/action/action.h"
#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include "../../include/action/combat.h"
#include <ncurses.h>

void actionPlayer(const Position newPosition, Entities *entities) {
    if (mvinch(newPosition.y, newPosition.x) == TEST_ENEMY_SYMBOL) {
        combatEnemy(entities->player,
                    findAttackedEnemy(newPosition, entities->enemyArray, entities->enemyCount), true);
    } else if (mvinch(newPosition.y, newPosition.x) == TEST_PASSIVE_SYMBOL) {
        combatPassive(entities->player,
                      findAttackedPassive(newPosition, entities->passiveArray, entities->passiveCount));
    } else {
        moveEntity(newPosition, &entities->player->position, entities->player->attributes.symbol);
    }
}

void actionEntities(Entities *entities) {
    actionEnemies(entities->enemyArray, entities->enemyCount, entities->player);
    actionPassives(entities->passiveArray, entities->passiveCount);
}

void actionEnemies(Enemy **enemyArray, const int enemyCount, Player* player) {
    for (int i = 0; i < enemyCount; i++) {
        if (areEntitiesBeside(enemyArray[i]->position, player->position)) {
            combatEnemy(player, enemyArray[i], false);
        } else {
            goToPlayer(enemyArray[i], player->position);
        }
    }
}

void actionPassives(Passive **passiveArray, const int passiveCount) {
    for (int i = 0; i < passiveCount; i++) {
        idleAndMove(passiveArray[i]);
    }
}