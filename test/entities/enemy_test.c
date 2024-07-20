#include "../../include/entities/enemy.h"
#include "../../include/action/movement.h"
#include "../../include/core/castaway.h"
#include <criterion/criterion.h>
#include <malloc.h>
#include <ncurses.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(initializeEnemy, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 0;
    const int damage = 0;
    const char symbol = 'E';

    Enemy *enemy = initializeEnemy(position, health, damage, symbol);

    cr_assert_eq(enemy->position.y, position.y);
    cr_assert_eq(enemy->position.x, position.x);
    cr_assert_eq(enemy->attributes.health, health);
    cr_assert_eq(enemy->attributes.damage, damage);
    cr_assert_eq(enemy->attributes.symbol, symbol);
    cr_assert_eq(enemy->attributes.isAlive, true);
    cr_assert_eq(mvinch(enemy->position.y, enemy->position.x), symbol);

    freeEnemy(&enemy);
}

Test(goToPlayer, basic, .init = setup, .fini = teardown) {
    Player *player = initializePlayer((Position) {0, 2});
    Enemy *enemy = initializeEnemy((Position) {0, 0}, 0, 0, 'E');

    goToPlayer(enemy, player->position);

    cr_assert_eq(enemy->position.y, 0);
    cr_assert_eq(enemy->position.x, 1);

    freePlayer(&player);
    freeEnemy(&enemy);
}