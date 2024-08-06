#include "../../include/core/draw.h"
#include "../../include/core/castaway.h"
#include <ncurses.h>
#include <criterion/criterion.h>

static void setup() {
    initializeScreen();
}

Test(drawSymbol, basic, .init = setup) {
    const Position position = {0, 0};
    const char symbol = '0';

    drawSymbol(position, symbol);

    cr_assert_eq(mvinch(position.y, position.x), symbol);
}

Test(drawEntityMovement, basic, .init = setup) {
    const Position newPosition = {0, 1};
    const Position oldPosition = {0, 0};
    const char tileSymbol = '.';
    const char entitySymbol = 'E';

    drawEntityMovement(newPosition, oldPosition, tileSymbol, entitySymbol);

    cr_assert_eq(mvinch(newPosition.y, newPosition.x), entitySymbol);
    cr_assert_eq(mvinch(oldPosition.y, oldPosition.x), tileSymbol);
}