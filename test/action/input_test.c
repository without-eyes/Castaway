#include "../../include/action/input.h"
#include "../../include/core/castaway.h"
#include "../../include/utils/draw.h"
#include <criterion/criterion.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(handleInput, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    Entities *entities = malloc(sizeof(Entities));
    *entities = (Entities) {initializePlayer(position), 0, NULL, 0, NULL};

    handleInput('s', entities);

    cr_assert_eq(entities->player->position.y, position.y + 1);
    cr_assert_eq(entities->player->position.x, position.x);

    freeEntities(&entities);
}

