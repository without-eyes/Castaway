#include "../../include/entities/entities.h"
#include "../../include/core/castaway.h"
#include "../../include/utils/draw.h"
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
    Entities *entities = (Entities *) malloc(sizeof(Entities));
    initializeEntities(&entities);

    cr_assert_eq(entities->player->attributes.health, 20);
    cr_assert_eq(entities->player->attributes.damage, 2);
    cr_assert_eq(entities->player->attributes.symbol, '@');
    cr_assert_eq(entities->player->attributes.isAlive, true);
    cr_assert_eq(mvinch(entities->player->position.y, entities->player->position.x),
                 entities->player->attributes.symbol);

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

Test(removeDeadEntities, basic, .init = setup, .fini = teardown) {
    Entities *entities = (Entities *) malloc(sizeof(Entities));
    entities->enemyCount = 1;
    entities->enemyArray = (Enemy **) malloc(entities->enemyCount * sizeof(Enemy *));
    entities->enemyArray[0] = initializeEnemy((Position) {0, 0}, 0, 10, 'E');
    entities->enemyArray[0]->attributes.isAlive = false;
    entities->passiveCount = 1;
    entities->passiveArray = (Passive **) malloc(entities->passiveCount * sizeof(Passive *));
    entities->passiveArray[0] = initializePassive((Position) {0, 1}, 0, 10, 'P');
    entities->passiveArray[0]->attributes.isAlive = false;

    removeDeadEntities(&entities);

    cr_assert_eq(entities->enemyCount, 0);
    cr_assert_eq(mvinch(0, 0), 'D');
    cr_assert_eq(entities->passiveCount, 0);
    cr_assert_eq(mvinch(0, 1), 'D');
}


Test(freeEntities, basic, .init = setup, .fini = teardown) {
    Entities *entities = (Entities *) malloc(sizeof(Entities));
    initializeEntities(&entities);

    freeEntities(&entities);

    cr_assert_null(entities);
}

