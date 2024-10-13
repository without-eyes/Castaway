#include "../../include/utils/draw.h"
#include "../../include/core/castaway.h"
#include <ncurses.h>
#include <criterion/criterion.h>

static void setup() {
    startGame(NULL);
}

static void teardown() {
    endwin();
}

TestSuite(drawSymbol, .init = setup, .fini = teardown);
TestSuite(initColors, .init = setup, .fini = teardown);

Test(drawSymbol, basic) {
    Position position = (Position){rand() % LINES, rand() % COLS};
    const char symbol = '0';

    drawSymbol(position, symbol);
    printf("Expected: '%c', Actual: '%c' at position (%d, %d)\n", symbol, mvinch(position.y, position.x) & A_CHARTEXT, position.y, position.x);

    cr_assert_eq(mvinch(position.y, position.x) & A_CHARTEXT, symbol);
}

Test(initColors, basic) {
  initColors();

  cr_assert(has_colors());
}