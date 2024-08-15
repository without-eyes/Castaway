#include "../../include/entities/passive.h"
#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include "../../include/utils/draw.h"
#include <stdlib.h>
#include <ncurses.h>

Passive *initializePassive(const Position position, const int health, const int damage, const chtype symbol) {
    Passive *passive = (Passive *) malloc(sizeof(Passive));

    passive->location = setLocationData(position);
    passive->attributes = initializeEntity(health, damage, symbol);

    drawSymbol(passive->location.position, passive->attributes.symbol);

    return passive;
}

void createPassive(Passive ***passiveArray, int *passiveCount) {
    *passiveCount = rand() % (TEST_PASSIVE_MAX_COUNT - TEST_PASSIVE_MIN_COUNT) + TEST_PASSIVE_MIN_COUNT;
    *passiveArray = (Passive **) malloc(*passiveCount * sizeof(Passive *));
    for (int i = 0; i < *passiveCount; i++) {
        (*passiveArray)[i] = initializePassive(getRandomPosition(), 10, 0, TEST_PASSIVE_SYMBOL);
    }
}

void removeDeadPassive(Passive ***passiveArray, int *passiveCount) {
    for (int i = 0; i < *passiveCount; i++) {
        if ((*passiveArray)[i]->attributes.isAlive) {
            continue;
        }

        drawSymbol((*passiveArray)[i]->location.position, TEST_DEAD_SYMBOL);

        if (i < *passiveCount - 1) {
            (*passiveArray)[i] = (*passiveArray)[*passiveCount - 1];
        }

        (*passiveArray)[*passiveCount - 1] = NULL;
        (*passiveCount)--;
    }
}

void freePassives(Passive ***passiveArray, const int passiveCount) {
    if (*passiveArray) {
        for (int i = 0; i < passiveCount; i++) {
            if ((*passiveArray)[i]) {
                freePassive(&(*passiveArray)[i]);
            }
        }
        free(*passiveArray);
        *passiveArray = NULL;
    }
}

void freePassive(Passive **passive) {
    if (*passive) {
        free(*passive);
        *passive = NULL;
    }
}

void idleAndMove(Passive *passive) {
    static int idleTime = 0;
    if (idleTime >= TEST_PASSIVE_IDLE_TIME) {
        idleTime = 0;
        randomMovement(passive);
    } else {
        idleTime += rand() % 4;
    }
}

void randomMovement(Passive *passive) {
    Position newPosition = passive->location.position;
    unsigned char direction = rand() % 4;
    switch (direction) {
        case 0:
            newPosition.y++;
            break;

        case 1:
            newPosition.y--;
            break;

        case 2:
            newPosition.x++;
            break;

        case 3:
            newPosition.x--;
            break;

        default:
            break;
    }
    moveEntity(newPosition, &passive->location, passive->attributes.symbol);
}