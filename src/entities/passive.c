#include "../../include/entities/passive.h"
#include "../../include/action/movement.h"
#include "../../include/core/macros.h"
#include <stdlib.h>
#include <ncurses.h>

Passive *initializePassive(const Position position, const int health, const int damage, const char symbol) {
    Passive *passive = (Passive *) malloc(sizeof(Passive));

    passive->position = position;
    passive->attributes = initializeEntity(health, damage, symbol);

    mvprintw(passive->position.y, passive->position.x, "%c", passive->attributes.symbol);

    return passive;
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
    Position newPosition;
    unsigned char direction = rand() % 4;
    switch (direction) {
        case 0:
            newPosition = (Position) {passive->position.y + 1, passive->position.x};
            moveEntity(newPosition, &passive->position, passive->attributes.symbol);
            break;

        case 1:
            newPosition = (Position) {passive->position.y - 1, passive->position.x};
            moveEntity(newPosition, &passive->position, passive->attributes.symbol);
            break;

        case 2:
            newPosition = (Position) {passive->position.y, passive->position.x + 1};
            moveEntity(newPosition, &passive->position, passive->attributes.symbol);
            break;

        case 3:
            newPosition = (Position) {passive->position.y, passive->position.x - 1};
            moveEntity(newPosition, &passive->position, passive->attributes.symbol);
            break;

        default:
            break;
    }
}