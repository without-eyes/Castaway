#include "../../include/entities/passive.h"
#include "../../include/core/movement.h"
#include "../../include/core/macros.h"
#include <stdlib.h>
#include <ncurses.h>

Passive *initialisePassive(const Position position, const int health, const int damage, const char symbol) {
    Passive *passive = (Passive *) malloc(sizeof(Passive));

    passive->attributes = initializeEntity(position, health, damage, symbol);

    mvprintw(passive->attributes.position.y, passive->attributes.position.x, "%c", passive->attributes.symbol);

    return passive;
}

void randomMovement(Passive *passive) {
    static int idleTime = 0;
    if (idleTime == TEST_PASSIVE_IDLE_TIME) {
        idleTime = 0;
        Position newPosition;
        unsigned char direction = rand() % 4;
        switch (direction) {
            case 0:
                newPosition = (Position) {passive->attributes.position.y + 1, passive->attributes.position.x};
                moveEntity(newPosition, &passive->attributes.position, passive->attributes.symbol);
                break;

            case 1:
                newPosition = (Position) {passive->attributes.position.y - 1, passive->attributes.position.x};
                moveEntity(newPosition, &passive->attributes.position, passive->attributes.symbol);
                break;

            case 2:
                newPosition = (Position) {passive->attributes.position.y, passive->attributes.position.x + 1};
                moveEntity(newPosition, &passive->attributes.position, passive->attributes.symbol);
                break;

            case 3:
                newPosition = (Position) {passive->attributes.position.y, passive->attributes.position.x - 1};
                moveEntity(newPosition, &passive->attributes.position, passive->attributes.symbol);
                break;

            default:
                break;
        }
    } else {
        idleTime++;
    }
}