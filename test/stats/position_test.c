#include "../../include/stats/position.h"
#include "../../include/core/macros.h"
#include "../../include/core/castaway.h"
#include <ncurses.h>
#include <criterion/criterion.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(getRandomPosition, basic, .init = setup, .fini = teardown) {
    Position position;

    position = getRandomPosition();

    cr_assert_geq(position.y, 0);
    cr_assert_leq(position.y, MAP_HEIGHT);
    cr_assert_geq(position.x, 0);
    cr_assert_leq(position.x, MAP_WIDTH);
}

Test(arePositionEquals, basic) {
    Position position1 = {0, 0};
    Position position2 = {0, 0};

    bool result = arePositionsEqual(position1, position2);

    cr_assert_eq(result, true);
}