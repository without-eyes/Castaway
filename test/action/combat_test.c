#include "../../include/action/combat.h"
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

Test(attack, basic, .init = setup, .fini = teardown) {
    const Attributes attackerAttributes = {10, 5, 'A', true};
    Attributes defenderAttributes = {10, 0, 'D', true};

    attack(&attackerAttributes, &defenderAttributes);

    cr_assert_eq(defenderAttributes.health, 5);
}

Test(combatEnemy, basic, .init = setup, .fini = teardown) {
    Player* player = initializePlayer((Position){0, 0});
    Enemy* enemy = initializeEnemy((Position){0, 1}, 10, 0, 'E');

    combatEnemy(player, enemy, true);

    cr_assert_eq(enemy->attributes.health, 8);

    freePlayer(&player);
    freeEnemy(&enemy);
}

Test(combatPassive, basic, .init = setup, .fini = teardown) {
    Player* player = initializePlayer((Position){0, 0});
    Passive* passive = initializePassive((Position){0, 1}, 10, 0, 'P');

    combatPassive(player, passive);

    cr_assert_eq(passive->attributes.health, 8);

    freePlayer(&player);
    freePassive(&passive);
}

Test(findAttackedEnemy, basic, .init = setup, .fini = teardown) {
    const int enemyCount = 1;
    Enemy **enemyArray = (Enemy**)malloc(enemyCount * sizeof(Enemy*));
    enemyArray[0] = initializeEnemy((Position){0, 1}, 10, 0, 'E');

    Enemy* attackedEnemy = findAttackedEnemy((Position){0, 1}, enemyArray, enemyCount);

    cr_assert_eq(enemyArray[0]->position.y, attackedEnemy->position.y);
    cr_assert_eq(enemyArray[0]->position.x, attackedEnemy->position.x);
    cr_assert_eq(enemyArray[0]->attributes.health, attackedEnemy->attributes.health);
    cr_assert_eq(enemyArray[0]->attributes.damage, attackedEnemy->attributes.damage);
    cr_assert_eq(enemyArray[0]->attributes.symbol, attackedEnemy->attributes.symbol);
    cr_assert_eq(enemyArray[0]->attributes.isAlive, attackedEnemy->attributes.isAlive);
    cr_assert_eq(mvinch(enemyArray[0]->position.y, enemyArray[0]->position.x), mvinch(attackedEnemy->position.y, attackedEnemy->position.x));

    freeEnemies(&enemyArray, enemyCount);
}

Test(findAttackedPassive, basic, .init = setup, .fini = teardown) {
    const int passiveCount = 1;
    Passive **passiveArray = (Passive**)malloc(passiveCount * sizeof(Passive*));
    passiveArray[0] = initializePassive((Position){0, 1}, 10, 0, 'P');

    Passive* attackedPassive = findAttackedPassive((Position){0, 1}, passiveArray, passiveCount);

    cr_assert_eq(passiveArray[0]->position.y, attackedPassive->position.y);
    cr_assert_eq(passiveArray[0]->position.x, attackedPassive->position.x);
    cr_assert_eq(passiveArray[0]->attributes.health, attackedPassive->attributes.health);
    cr_assert_eq(passiveArray[0]->attributes.damage, attackedPassive->attributes.damage);
    cr_assert_eq(passiveArray[0]->attributes.symbol, attackedPassive->attributes.symbol);
    cr_assert_eq(passiveArray[0]->attributes.isAlive, attackedPassive->attributes.isAlive);
    cr_assert_eq(mvinch(passiveArray[0]->position.y, passiveArray[0]->position.x), mvinch(attackedPassive->position.y, attackedPassive->position.x));

    freePassives(&passiveArray, passiveCount);
}
