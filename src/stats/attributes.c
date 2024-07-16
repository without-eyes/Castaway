#include "../../include/stats/attributes.h"

Attributes initializeEntity(const int health, const int damage, const char symbol) {
    Attributes attributes;

    attributes.health = health;
    attributes.damage = damage;
    attributes.symbol = symbol;
    attributes.isAlive = true;

    return attributes;
}