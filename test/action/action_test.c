#include "../../include/action/action.h"
#include "../../include/core/castaway.h"
#include "../../include/core/draw.h"
#include "criterion/criterion.h"

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(actionPlayer, basic, .init = setup, .fini = teardown) {
    const Position position = {0, 0};
    const Position newPosition = {1, 0};
    Entities *entities = malloc(sizeof(Entities));
    *entities = (Entities){initializePlayer(position), 0, NULL, 0, NULL};

    actionPlayer(newPosition, entities);

    cr_assert_eq(entities->player->position.y, position.y + 1);
    cr_assert_eq(entities->player->position.x, position.x);

    freeEntities(&entities);
}

Test(actionEntities, basic, .init = setup, .fini = teardown) {
    Entities* entities = (Entities *) malloc(sizeof(Entities));
    entities->player = initializePlayer((Position){0, 2});
    entities->enemyCount = 1;
    entities->enemyArray = (Enemy **) malloc(entities->enemyCount * sizeof(Enemy *));
    entities->enemyArray[0] = initializeEnemy((Position){0, 0}, 10, 10, 'E');
    entities->passiveCount = 1;
    entities->passiveArray = (Passive **) malloc(entities->passiveCount * sizeof(Passive *));
    entities->passiveArray[0] = initializePassive((Position){0, 0}, 10, 0, 'P');

    actionEntities(entities);

    cr_assert_eq(entities->enemyArray[0]->position.y, 0);
    cr_assert_eq(entities->enemyArray[0]->position.x, 1);
    cr_assert_eq(entities->passiveArray[0]->position.y, 0);
    cr_assert_eq(entities->passiveArray[0]->position.x, 0);

    freeEntities(&entities);
}

Test(actionEnemies, basic, .init = setup, .fini = teardown) {
    Enemy** enemies = (Enemy **) malloc(1 * sizeof(Enemy *));
    enemies[0] = initializeEnemy((Position){0, 0}, 10, 10, 'E');
    Player* player = initializePlayer((Position){0, 2});

    actionEnemies(enemies, 1, player);

    cr_assert_eq(enemies[0]->position.y, 0);
    cr_assert_eq(enemies[0]->position.x, 1);

    freeEnemies(&enemies, 1);
}

Test(actionPassives, basic, .init = setup, .fini = teardown) {
    Passive** passives = (Passive **) malloc(1 * sizeof(Passive *));
    passives[0] = initializePassive((Position){0, 0}, 10, 0, 'P');

    actionPassives(passives, 1);

    cr_assert_eq(passives[0]->position.y, 0);
    cr_assert_eq(passives[0]->position.x, 0);

    freePassives(&passives, 1);
}