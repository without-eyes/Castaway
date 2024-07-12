#include "../../include/entities/passive.h"
#include "../../include/core/movement.h"
#include <stdlib.h>

Passive *initialisePassive(Position position, int health, int damage, char symbol) {
    Passive *passive = (Passive *) malloc(sizeof(Passive));

    passive->attributes = initializeEntity(position, health, damage, symbol);

    mvprintw(passive->attributes.position.y, passive->attributes.position.x, "%c", passive->attributes.symbol);

    return passive;
}

void randomMovement(Passive *passive) {
    unsigned char direction = rand() % 6;
    switch (direction) {
        case 1:
            moveEntity(passive->attributes.position.y + 1, passive->attributes.position.x,
                       &passive->attributes.position, passive->attributes.symbol);
            break;

        case 2:
            moveEntity(passive->attributes.position.y - 1, passive->attributes.position.x,
                       &passive->attributes.position, passive->attributes.symbol);
            break;

        case 3:
            moveEntity(passive->attributes.position.y, passive->attributes.position.x + 1,
                       &passive->attributes.position, passive->attributes.symbol);
            break;

        case 4:
            moveEntity(passive->attributes.position.y, passive->attributes.position.x - 1,
                       &passive->attributes.position, passive->attributes.symbol);
            break;

        case 5:
        case 6:
        default:
            break;
    }
}