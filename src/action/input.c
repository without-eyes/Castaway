#include <ctype.h>
#include "../../include/action/input.h"
#include "../../include/action/action.h"
#include "../../include/macros/key_macros.h"

void handleInput(const char input, Entities *entities) {
    Position position = entities->player->location.position;
    switch (tolower(input)) {
        case GO_UP_KEY:
            position.y--;
            break;

        case GO_LEFT_KEY:
            position.x--;
            break;

        case GO_DOWN_KEY:
            position.y++;
            break;

        case GO_RIGHT_KEY:
            position.x++;
            break;

        default:
            break;
    }
    executePlayerAction(position, entities);
}

