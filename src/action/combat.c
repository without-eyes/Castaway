#include "../../include/action/combat.h"
#include <stdlib.h>

void attack(const Attributes *attackerAttributes, Attributes *defenderAttributes) {
    defenderAttributes->health -= attackerAttributes->damage;
    if (defenderAttributes->health <= 0) {
        defenderAttributes->isAlive = false;
    }
}

void combatEnemy(Player *player, Enemy *enemy, const bool playerTurn) {
    if (playerTurn) {
        attack(&player->attributes, &enemy->attributes);
    } else {
        attack(&enemy->attributes, &player->attributes);
    }
}

void combatPassive(const Player *player, Passive *passive) {
    attack(&player->attributes, &passive->attributes);
}

Enemy *findAttackedEnemy(const Position position, Enemy **enemyArray, const int enemyCount) {
    for (int i = 0; i < enemyCount; i++) {
        if (arePositionsEqual(enemyArray[i]->location.position, position)) {
            return enemyArray[i];
        }
    }
    return NULL;
}

Passive *findAttackedPassive(const Position position, Passive **passiveArray, const int passiveCount) {
    for (int i = 0; i < passiveCount; i++) {
        if (arePositionsEqual(passiveArray[i]->location.position, position)) {
            return passiveArray[i];
        }
    }
    return NULL;
}