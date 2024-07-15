#include "../../include/core/combat.h"
#include <stdlib.h>

void attack(const Attributes *attackerAttributes, Attributes *defenderAttributes) {
    defenderAttributes->health -= attackerAttributes->damage;
    if (defenderAttributes->health <= 0) {
        defenderAttributes->isAlive = false;
    }
}

void combatEnemy(const Player *player, const Enemy *enemy, const bool playerTurn) {
    if (playerTurn) {
        attack(&player->attributes, &enemy->attributes);
    } else {
        attack(&enemy->attributes, &player->attributes);
    }
}

void combatPassive(const Player *player, const Passive *passive) {
    attack(&player->attributes, &passive->attributes);
}

Enemy *findAttackedEnemy(const Position position, const Enemy **enemyArray, const int enemyCount) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemyArray[i]->attributes.position.y == position.y &&
            enemyArray[i]->attributes.position.x == position.x) {
            return enemyArray[i];
        }
    }
    return NULL;
}

Passive *findAttackedPassive(const Position position, const Passive **passiveArray, const int passiveCount) {
    for (int i = 0; i < passiveCount; i++) {
        if (passiveArray[i]->attributes.position.y == position.y &&
            passiveArray[i]->attributes.position.x == position.x) {
            return passiveArray[i];
        }
    }
    return NULL;
}