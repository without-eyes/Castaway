#include "../../include/stats/position.h"
#include "../../include/core/castaway.h"
#include "../../include/map/map.h"
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

Test(areEntitiesBeside, basic) {
    Position position1 = {0, 0};
    Position position2 = {0, 1};

    bool result = areEntitiesBeside(position1, position2);

    cr_assert_eq(result, true);
}