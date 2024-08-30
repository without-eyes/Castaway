#include "../../include/action/movement.h"
#include "../../include/core/castaway.h"
#include "../../include/utils/draw.h"
#include <criterion/criterion.h>

static void setup() {
    setScreenAttributes();
    setMap();
}

static void teardown() {
    endGame();
}

Test(moveEntity, basic, .init = setup, .fini = teardown) {
    const Position newPosition = {1, 1};
    Position entityPosition = {0, 0};
    const char symbol = 'T';

    moveEntity(newPosition, &entityPosition, symbol);
    cr_assert_eq(entityPosition.y, newPosition.y);
    cr_assert_eq(entityPosition.x, newPosition.x);
}