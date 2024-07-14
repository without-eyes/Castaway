#include "../../include/entities/enemy.h"
#include "../../include/core/movement.h"
#include "../../include/core/castaway.h"
#include <criterion/criterion.h>
#include <malloc.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(initialiseEnemy, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 0;
    const int damage = 0;
    const char symbol = 'E';

    Enemy *enemy = initialiseEnemy(position, health, damage, symbol);

    cr_assert_eq(enemy->attributes.position.y, position.y);
    cr_assert_eq(enemy->attributes.position.x, position.x);
    cr_assert_eq(enemy->attributes.health, health);
    cr_assert_eq(enemy->attributes.damage, damage);
    cr_assert_eq(enemy->attributes.symbol, symbol);
    cr_assert_eq(enemy->attributes.isAlive, true);
    cr_assert_eq(mvinch(enemy->attributes.position.y, enemy->attributes.position.x), symbol);

    free(enemy);
    enemy = NULL;
}

Test(goToPlayer, basic, .init = setup, .fini = teardown) {
    Player *player = initialisePlayer((Position) {0, 2});
    Enemy *enemy = initialiseEnemy((Position) {0, 0}, 0, 0, 'E');

    goToPlayer(enemy, player->attributes.position);

    cr_assert_eq(enemy->attributes.position.y, 0);
    cr_assert_eq(enemy->attributes.position.x, 1);
}