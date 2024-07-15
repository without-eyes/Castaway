#include "../../include/core/input.h"
#include "../../include/core/combat.h"
#include "../../include/core/movement.h"
#include "../../include/core/macros.h"
#include <ncurses.h>

void handlePlayerInput(const char input, Entities *entities) {
    Position position;
    switch (input) {
        case 'W':
        case 'w':
            position = (Position) {entities->player->attributes.position.y - 1,
                                   entities->player->attributes.position.x};
            action(position, entities);
            break;

        case 'A':
        case 'a':
            position = (Position) {entities->player->attributes.position.y,
                                   entities->player->attributes.position.x - 1};
            action(position, entities);
            break;

        case 'S':
        case 's':
            position = (Position) {entities->player->attributes.position.y + 1,
                                   entities->player->attributes.position.x};
            action(position, entities);
            break;

        case 'D':
        case 'd':
            position = (Position) {entities->player->attributes.position.y,
                                   entities->player->attributes.position.x + 1};
            action(position, entities);
            break;

        default:
            break;
    }
}

void action(const Position newPosition, Entities *entities) {
    if (mvinch(newPosition.y, newPosition.x) == TEST_ENEMY_SYMBOL) {
        combatEnemy(entities->player,
                    findAttackedEnemy(newPosition, entities->enemyArray, entities->enemyCount), true);
    } else if (mvinch(newPosition.y, newPosition.x) == TEST_PASSIVE_SYMBOL) {
        combatPassive(entities->player,
                      findAttackedPassive(newPosition, entities->passiveArray, entities->passiveCount));
    } else {
        moveEntity(newPosition, &entities->player->attributes.position, entities->player->attributes.symbol);
    }
}