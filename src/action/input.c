#include "../../include/action/input.h"
#include "../../include/action/action.h"

void handleInput(const char input, Entities *entities) {
    Position position;
    switch (input) {
        case 'W':
        case 'w':
            position = (Position) {entities->player->location.position.y - 1, entities->player->location.position.x};
            actionPlayer(position, entities);
            break;

        case 'A':
        case 'a':
            position = (Position) {entities->player->location.position.y, entities->player->location.position.x - 1};
            actionPlayer(position, entities);
            break;

        case 'S':
        case 's':
            position = (Position) {entities->player->location.position.y + 1, entities->player->location.position.x};
            actionPlayer(position, entities);
            break;

        case 'D':
        case 'd':
            position = (Position) {entities->player->location.position.y, entities->player->location.position.x + 1};
            actionPlayer(position, entities);
            break;

        default:
            break;
    }
}

