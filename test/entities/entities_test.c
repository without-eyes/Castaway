#include "../../include/entities/entities.h"
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

Test(initializeEntities, basic, .init = setup, .fini = teardown) {
    Player *player = NULL;
    const int enemyCount = 1;
    Enemy **enemyArray = NULL;
    const int passiveCount = 1;
    Passive **passiveArray = NULL;

    initializeEntities(&player, &enemyArray, enemyCount, &passiveArray, passiveCount);

    cr_assert_eq(player->attributes.health, 20);
    cr_assert_eq(player->attributes.damage, 2);
    cr_assert_eq(player->attributes.symbol, '@');
    cr_assert_eq(player->attributes.isAlive, true);
    cr_assert_eq(mvinch(player->attributes.position.y, player->attributes.position.x), player->attributes.symbol);

    cr_assert_eq(enemyArray[0]->attributes.health, 15);
    cr_assert_eq(enemyArray[0]->attributes.damage, 2);
    cr_assert_eq(enemyArray[0]->attributes.symbol, 'E');
    cr_assert_eq(enemyArray[0]->attributes.isAlive, true);
    cr_assert_eq(mvinch(enemyArray[0]->attributes.position.y, enemyArray[0]->attributes.position.x),
                 enemyArray[0]->attributes.symbol);

    cr_assert_eq(passiveArray[0]->attributes.health, 10);
    cr_assert_eq(passiveArray[0]->attributes.damage, 0);
    cr_assert_eq(passiveArray[0]->attributes.symbol, 'P');
    cr_assert_eq(passiveArray[0]->attributes.isAlive, true);
    cr_assert_eq(mvinch(passiveArray[0]->attributes.position.y, passiveArray[0]->attributes.position.x),
                 passiveArray[0]->attributes.symbol);
}

Test(createPlayer, basic, .init = setup, .fini = teardown) {
    Player *player = NULL;

    createPlayer(&player);

    cr_assert_eq(player->attributes.health, 20);
    cr_assert_eq(player->attributes.damage, 2);
    cr_assert_eq(player->attributes.symbol, '@');
    cr_assert_eq(player->attributes.isAlive, true);
    cr_assert_eq(mvinch(player->attributes.position.y, player->attributes.position.x), player->attributes.symbol);
}

Test(createEnemies, basic, .init = setup, .fini = teardown) {
    const int enemyCount = 1;
    Enemy **enemyArray = NULL;

    createEnemies(&enemyArray, enemyCount);

    cr_assert_eq(enemyArray[0]->attributes.health, 15);
    cr_assert_eq(enemyArray[0]->attributes.damage, 2);
    cr_assert_eq(enemyArray[0]->attributes.symbol, 'E');
    cr_assert_eq(enemyArray[0]->attributes.isAlive, true);
    cr_assert_eq(mvinch(enemyArray[0]->attributes.position.y, enemyArray[0]->attributes.position.x),
                 enemyArray[0]->attributes.symbol);
}

Test(createPassive, basic, .init = setup, .fini = teardown) {
    const int passiveCount = 1;
    Passive **passiveArray = NULL;

    createPassive(&passiveArray, passiveCount);

    cr_assert_eq(passiveArray[0]->attributes.health, 10);
    cr_assert_eq(passiveArray[0]->attributes.damage, 0);
    cr_assert_eq(passiveArray[0]->attributes.symbol, 'P');
    cr_assert_eq(passiveArray[0]->attributes.isAlive, true);
    cr_assert_eq(mvinch(passiveArray[0]->attributes.position.y, passiveArray[0]->attributes.position.x),
                 passiveArray[0]->attributes.symbol);
}

Test(freeEntities, basic, .init = setup, .fini = teardown) {
    Player *player = NULL;
    const int enemyCount = 1;
    Enemy **enemyArray = NULL;
    const int passiveCount = 1;
    Passive **passiveArray = NULL;

    initializeEntities(&player, &enemyArray, enemyCount, &passiveArray, passiveCount);

    freeEntities(&player, &enemyArray, enemyCount, &passiveArray, passiveCount);

    cr_assert_null(player);
    cr_assert_null(enemyArray);
    cr_assert_null(passiveArray);
}
