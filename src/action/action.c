#include "../../include/action/action.h"
#include "../../include/action/movement.h"
#include "../../include/macros/test_macros.h"
#include "../../include/action/combat.h"
#include "../../include/map/map.h"
#include <ncurses.h>

void executePlayerAction(const Position newPosition, Entities *entities) {
    chtype newPositionTile = map[newPosition.y][newPosition.x];
    switch (newPositionTile) {
        case TEST_ENEMY_SYMBOL:
            Enemy *attackedEnemy = findAttackedEnemy(newPosition, entities->enemyArray, entities->enemyCount);
            attack(&entities->player->attributes, &attackedEnemy->attributes);
            break;

        case TEST_PASSIVE_SYMBOL:
            Passive *attackedPassive = findAttackedPassive(newPosition, entities->passiveArray, entities->passiveCount);
            attack(&entities->player->attributes, &attackedPassive->attributes);
            break;

        default:
            moveEntity(newPosition, &entities->player->location, entities->player->attributes.symbol);
    }
}

void executeEntitiesActions(Entities *entities) {
    executeEnemiesActions(entities->enemyArray, entities->enemyCount, entities->player);
    executePassivesActions(entities->passiveArray, entities->passiveCount);
}

void executeEnemiesActions(Enemy **enemyArray, const int enemyCount, Player *player) {
    for (int i = 0; i < enemyCount; i++) {
        if (areEntitiesBeside(enemyArray[i]->location.position, player->location.position)) {
            attack(&enemyArray[i]->attributes, &player->attributes);
        } else {
            goToPlayer(enemyArray[i], player->location.position);
        }
    }
}

void executePassivesActions(Passive **passiveArray, const int passiveCount) {
    for (int i = 0; i < passiveCount; i++) {
        idleAndMove(passiveArray[i]);
    }
}