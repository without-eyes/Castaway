#include "../../include/action/movement.h"
#include "../../include/utils/draw.h"
#include "../../include/core/macros.h"
#include <ncurses.h>

void moveEntity(const Position newPosition, Location *entityLocation, const chtype entitySymbol) {
    char tileSymbol = mvinch(newPosition.y, newPosition.x) & A_CHARTEXT;
    if (tileSymbol == PLAIN_GROUND_SYMBOL ||
        tileSymbol == GRASS_SYMBOL_1 ||
        tileSymbol == GRASS_SYMBOL_2 ||
        tileSymbol == GRASS_SYMBOL_3 ||
        tileSymbol == GRASS_SYMBOL_4 ||
        tileSymbol == FLOWER_SYMBOL) {
        drawEntityMovement(newPosition, entityLocation->position, entityLocation->tileSymbol, entitySymbol);
        entityLocation->tileSymbol = tileSymbol;
        entityLocation->position.y = newPosition.y;
        entityLocation->position.x = newPosition.x;
    }

}
