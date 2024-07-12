#include "../../include/core/movement.h"
#include "../../include/core/castaway.h"
#include "../../include/entities/entities.h"
#include <criterion/criterion.h>

static void setup() {
    initializeScreen();
    setMap();
}

static void teardown() {
    endGame();
}

Test(moveEntity, basic, .init = setup, .fini = teardown) {
    const int y = 1;
    const int x = 1;
    Position position = {0, 0};
    const char symbol = 'T';

    moveEntity(y, x, &position, symbol);
    cr_assert_eq(position.y, y);
    cr_assert_eq(position.x, x);
}

Test(moveAllEntities, basic, .init = setup, .fini = teardown) {
//    Player* player = NULL;
//    const int enemyCount = 1;
//    Enemy** enemyArray = NULL;
//    const int passiveCount = 1;
//    Passive** passiveArray = NULL;
//    initializeEntities(&player, &enemyArray, enemyCount, &passiveArray, passiveCount);
//
//    moveAllEntities(player, enemyArray, enemyCount, passiveArray, passiveCount);
}