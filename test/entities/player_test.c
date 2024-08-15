#include "../../include/entities/player.h"
#include "../../include/core/castaway.h"
#include "../../include/utils/draw.h"
#include <criterion/criterion.h>
#include <ncurses.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(initializePlayer, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 20;
    const int damage = 2;
    const char symbol = '@';

    Player *player = initializePlayer(position);

    cr_assert_eq(player->position.y, position.y);
    cr_assert_eq(player->position.x, position.x);
    cr_assert_eq(player->attributes.health, health);
    cr_assert_eq(player->attributes.damage, damage);
    cr_assert_eq(player->attributes.symbol, symbol);
    cr_assert_eq(player->attributes.isAlive, true);
    cr_assert_eq(mvinch(player->position.y, player->position.x), symbol);

    freePlayer(&player);
}

Test(createPlayer, basic, .init = setup, .fini = teardown) {
    Player *player = NULL;

    createPlayer(&player);

    cr_assert_eq(player->attributes.health, 20);
    cr_assert_eq(player->attributes.damage, 2);
    cr_assert_eq(player->attributes.symbol, '@');
    cr_assert_eq(player->attributes.isAlive, true);
    cr_assert_eq(mvinch(player->position.y, player->position.x), player->attributes.symbol);

    freePlayer(&player);
}

Test(freePlayer, basic, .init = setup, .fini = teardown) {
    Player *player = initializePlayer(getRandomPosition());

    freePlayer(&player);

    cr_assert_null(player);
}
