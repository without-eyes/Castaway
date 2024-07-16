#include "../../include/stats/attributes.h"
#include <criterion/criterion.h>

Test(initializeEntity, basic) {
    const Position position = {0, 0};
    const int health = 0;
    const int damage = 0;
    const char symbol = '0';

    Attributes attributes1 = initializeEntity(position, health, damage, symbol);
    Attributes attributes2 = {position, health, damage, symbol};

    cr_assert_eq(attributes1.position.y, attributes2.position.y);
    cr_assert_eq(attributes1.position.x, attributes2.position.x);
    cr_assert_eq(attributes1.health, attributes2.health);
    cr_assert_eq(attributes1.damage, attributes2.damage);
    cr_assert_eq(attributes1.symbol, attributes2.symbol);

}