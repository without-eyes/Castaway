#include "../../include/entities/player.h"
#include "../../include/core/castaway.h"
#include <criterion/criterion.h>
#include <ncurses.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(initialisePlayer, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 20;
    const int damage = 2;
    const char symbol = '@';

    Player *player = initialisePlayer(position);

    cr_assert_eq(player->position.y, position.y);
    cr_assert_eq(player->position.x, position.x);
    cr_assert_eq(player->attributes.health, health);
    cr_assert_eq(player->attributes.damage, damage);
    cr_assert_eq(player->attributes.symbol, symbol);
    cr_assert_eq(player->attributes.isAlive, true);
    cr_assert_eq(mvinch(player->position.y, player->position.x), symbol);

    freePlayer(&player);
}

