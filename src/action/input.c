#include "../../include/action/input.h"
#include "../../include/action/action.h"

void handleInput(const char input, Entities *entities) {
    Position position = entities->player->location.position;
    switch (input) {
        case 'W':
        case 'w':
            position.y--;
            break;

        case 'A':
        case 'a':
            position.x--;
            break;

        case 'S':
        case 's':
            position.y++;
            break;

        case 'D':
        case 'd':
            position.x++;
            break;

        default:
            break;
    }
    actionPlayer(position, entities);
}

