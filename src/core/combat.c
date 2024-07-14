#include "../../include/core/combat.h"

void combatEnemy(Player* player, Enemy* enemy, bool playerTurn) {
    if (playerTurn) {
        enemy->attributes.health -= player->attributes.damage;
        if (enemy->attributes.health <= 0) {
            enemy->attributes.isAlive = false;
        }
    } else {
        player->attributes.health -= enemy->attributes.damage;
        if (player->attributes.health <= 0) {
            player->attributes.isAlive = false;
        }
    }
}

void combatPassive(Player* player, Passive* passive) {
    passive->attributes.health -= player->attributes.damage;
    if (passive->attributes.health <= 0) {
        passive->attributes.isAlive = false;
    }
}

Enemy* findAttackedEnemy(Enemy **enemyArray, int enemyCount, int y, int x) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemyArray[i]->attributes.position.y == y &&
            enemyArray[i]->attributes.position.x == x) {
            return enemyArray[i];
        }
    }
    return NULL;
}

Passive* findAttackedPassive(Passive **passiveArray, int passiveCount, int y, int x) {
    for (int i = 0; i < passiveCount; i++) {
        if (passiveArray[i]->attributes.position.y == y &&
                passiveArray[i]->attributes.position.x == x) {
            return passiveArray[i];
        }
    }
    return NULL;
}