#include "../../include/entities/entities.h"
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

Test(initializeEntities, basic, .init = setup, .fini = teardown) {
    Entities* entities = (Entities*)malloc(sizeof(Entities));
    initializeEntities(&entities);

    cr_assert_eq(entities->player->attributes.health, 20);
    cr_assert_eq(entities->player->attributes.damage, 2);
    cr_assert_eq(entities->player->attributes.symbol, '@');
    cr_assert_eq(entities->player->attributes.isAlive, true);
    cr_assert_eq(mvinch(entities->player->position.y, entities->player->position.x), entities->player->attributes.symbol);

    for (int i = 0; i < entities->enemyCount; i++) {
        cr_assert_eq(entities->enemyArray[i]->attributes.health, 15);
        cr_assert_eq(entities->enemyArray[i]->attributes.damage, 2);
        cr_assert_eq(entities->enemyArray[i]->attributes.symbol, 'E');
        cr_assert_eq(entities->enemyArray[i]->attributes.isAlive, true);
        cr_assert_eq(mvinch(entities->enemyArray[i]->position.y, entities->enemyArray[i]->position.x),
                     entities->enemyArray[i]->attributes.symbol);
    }

    for (int i = 0; i < entities->passiveCount; i++) {
        cr_assert_eq(entities->passiveArray[i]->attributes.health, 10);
        cr_assert_eq(entities->passiveArray[i]->attributes.damage, 0);
        cr_assert_eq(entities->passiveArray[i]->attributes.symbol, 'P');
        cr_assert_eq(entities->passiveArray[i]->attributes.isAlive, true);
        cr_assert_eq(mvinch(entities->passiveArray[i]->position.y, entities->passiveArray[i]->position.x),
                     entities->passiveArray[i]->attributes.symbol);
    }

    freeEntities(&entities);
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

Test(createEnemies, basic, .init = setup, .fini = teardown) {
    int enemyCount;
    Enemy **enemyArray = NULL;

    createEnemies(&enemyArray, &enemyCount);

    for (int i = 0; i < enemyCount; i++) {
        cr_assert_eq(enemyArray[i]->attributes.health, 15);
        cr_assert_eq(enemyArray[i]->attributes.damage, 2);
        cr_assert_eq(enemyArray[i]->attributes.symbol, 'E');
        cr_assert_eq(enemyArray[i]->attributes.isAlive, true);
        cr_assert_eq(mvinch(enemyArray[i]->position.y, enemyArray[i]->position.x),
                     enemyArray[i]->attributes.symbol);
    }

    freeEnemies(&enemyArray, enemyCount);
}

Test(createPassive, basic, .init = setup, .fini = teardown) {
    int passiveCount;
    Passive **passiveArray = NULL;

    createPassive(&passiveArray, &passiveCount);

    for (int i = 0; i < passiveCount; i++) {
        cr_assert_eq(passiveArray[i]->attributes.health, 10);
        cr_assert_eq(passiveArray[i]->attributes.damage, 0);
        cr_assert_eq(passiveArray[i]->attributes.symbol, 'P');
        cr_assert_eq(passiveArray[i]->attributes.isAlive, true);
        cr_assert_eq(mvinch(passiveArray[i]->position.y, passiveArray[i]->position.x),
                     passiveArray[i]->attributes.symbol);
    }

    freePassives(&passiveArray, passiveCount);
}

Test(freeEntities, basic, .init = setup, .fini = teardown) {
    Entities* entities = (Entities*)malloc(sizeof(Entities));
    initializeEntities(&entities);

    freeEntities(&entities);

    cr_assert_null(entities);
}

Test(freePlayer, basic, .init = setup, .fini = teardown) {
    Player* player = initializePlayer(getRandomPosition());

    freePlayer(&player);

    cr_assert_null(player);
}

Test(freeEnemies, basic, .init = setup, .fini = teardown) {
    int enemyCount;
    Enemy** enemyArray;
    createEnemies(&enemyArray, &enemyCount);

    freeEnemies(&enemyArray, enemyCount);

    cr_assert_null(enemyArray);
}

Test(freeEnemy, basic, .init = setup, .fini = teardown) {
    Enemy* enemy = initializeEnemy((Position){0, 0}, 1, 1, 'E');

    freeEnemy(&enemy);

    cr_assert_null(enemy);
}

Test(freePassives, basic, .init = setup, .fini = teardown) {
    int passiveCount;
    Passive** passiveArray;
    createPassive(&passiveArray, &passiveCount);

    freePassives(&passiveArray, passiveCount);

    cr_assert_null(passiveArray);
}

Test(freePassive, basic, .init = setup, .fini = teardown) {
    Passive* passive = initializePassive((Position){0, 0}, 1, 1, 'P');

    freePassive(&passive);

    cr_assert_null(passive);
}
