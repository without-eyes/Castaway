#include "../../include/entities/passive.h"
#include "../../include/core/castaway.h"
#include <stdlib.h>
#include <criterion/criterion.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(initialisePassive, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 0;
    const int damage = 0;
    const char symbol = 'P';

    Passive *passive = initialisePassive(position, health, damage, symbol);

    cr_assert_eq(passive->attributes.position.y, position.y);
    cr_assert_eq(passive->attributes.position.x, position.x);
    cr_assert_eq(passive->attributes.health, health);
    cr_assert_eq(passive->attributes.damage, damage);
    cr_assert_eq(passive->attributes.symbol, symbol);
    cr_assert_eq(passive->attributes.isAlive, true);
    cr_assert_eq(mvinch(passive->attributes.position.y, passive->attributes.position.x), symbol);

    free(passive);
    passive = NULL;
}