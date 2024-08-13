#include "../../include/entities/enemy.h"
#include "../../include/action/movement.h"
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

Test(removeDeadEnemies, basic, .init = setup, .fini = teardown) {
    int enemyCount = 1;
    Enemy** enemyArray = (Enemy **) malloc(enemyCount * sizeof(Enemy *));
    enemyArray[0] = initializeEnemy((Position){0, 0}, 0, 10, 'E');
    enemyArray[0]->attributes.isAlive = false;

    removeDeadEnemies(&enemyArray, &enemyCount);

    cr_assert_eq(enemyCount, 0);
    cr_assert_eq(mvinch(0, 0), 'D');

    freeEnemies(&enemyArray, enemyCount);
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

Test(goToPlayer, basic, .init = setup, .fini = teardown) {
    Player *player = initializePlayer((Position) {0, 2});
    Enemy *enemy = initializeEnemy((Position) {0, 0}, 0, 0, 'E');

    goToPlayer(enemy, player->position);

    cr_assert_eq(enemy->position.y, 0);
    cr_assert_eq(enemy->position.x, 1);

    freePlayer(&player);
    freeEnemy(&enemy);
}