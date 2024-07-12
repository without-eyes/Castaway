#include "../../include/entities/player.h"
#include "../../include/core/castaway.h"
#include "../../include/core/movement.h"
#include <malloc.h>
#include <criterion/criterion.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(initialisePlayer, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 10;
    const int damage = 10;
    const char symbol = '@';

    Player *player = initialisePlayer(position);

    cr_assert_eq(player->attributes.position.y, position.y);
    cr_assert_eq(player->attributes.position.x, position.x);
    cr_assert_eq(player->attributes.health, health);
    cr_assert_eq(player->attributes.damage, damage);
    cr_assert_eq(player->attributes.symbol, symbol);
    cr_assert_eq(mvinch(player->attributes.position.y, player->attributes.position.x), symbol);

    free(player);
    player = NULL;
}

Test(handleInput, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};

    Player *player = initialisePlayer(position);

    handleInput('s', player);

    cr_assert_eq(player->attributes.position.y, position.y + 1);
    cr_assert_eq(player->attributes.position.x, position.x);

    free(player);
    player = NULL;
}