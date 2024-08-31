#include "../../include/action/combat.h"

inline void attack(const Attributes *attackerAttributes, Attributes *defenderAttributes) {
    defenderAttributes->health -= attackerAttributes->damage;
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