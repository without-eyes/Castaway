#include "../../include/entities/passive.h"
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

Test(initializePassive, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const int health = 0;
    const int damage = 0;
    const char symbol = 'P';

    Passive *passive = initializePassive(position, health, damage, symbol);

    cr_assert_eq(passive->position.y, position.y);
    cr_assert_eq(passive->position.x, position.x);
    cr_assert_eq(passive->attributes.health, health);
    cr_assert_eq(passive->attributes.damage, damage);
    cr_assert_eq(passive->attributes.symbol, symbol);
    cr_assert_eq(passive->attributes.isAlive, true);
    cr_assert_eq(mvinch(passive->position.y, passive->position.x), symbol);

    freePassive(&passive);
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

Test(removeDeadPassive, basic, .init = setup, .fini = teardown) {
    int passiveCount = 1;
    Passive** passiveArray = (Passive **) malloc(passiveCount * sizeof(Passive *));
    passiveArray[0] = initializePassive((Position){0, 0}, 0, 10, 'P');
    passiveArray[0]->attributes.isAlive = false;

    removeDeadPassive(&passiveArray, &passiveCount);

    cr_assert_eq(passiveCount, 0);
    cr_assert_eq(mvinch(0, 0), 'D');

    freePassives(&passiveArray, passiveCount);
}

Test(freePassives, basic, .init = setup, .fini = teardown) {
    int passiveCount;
    Passive** passiveArray;

    createPassive(&passiveArray, &passiveCount);

    freePassives(&passiveArray, passiveCount);

    cr_assert_null(passiveArray);
}

Test(freePassive, basic, .init = setup, .fini = teardown) {
    Passive* passive = initializePassive((Position){0, 0}, 1, 0, 'P');

    freePassive(&passive);

    cr_assert_null(passive);
}

Test(idleAndMove, basic, .init = setup, .fini = teardown) {
    Position spawnPosition = {0, 0};
    Passive* passive = initializePassive(spawnPosition, 1, 0, 'P');

    idleAndMove(passive);

    cr_assert_eq(passive->position.y, spawnPosition.y);
    cr_assert_eq(passive->position.x, spawnPosition.x);
}

Test(randomMovement, basic, .init = setup, .fini = teardown) {
    Position spawnPosition = {1, 1};
    Passive* passive = initializePassive(spawnPosition, 1, 0, 'P');

    randomMovement(passive);

    cr_assert_eq(passive->position.y != spawnPosition.y || passive->position.x != spawnPosition.x, true);
}