#include "../../include/core/attributes.h"

Attributes initializeEntity(const Position position, const int health, const int damage, const char symbol) {
    Attributes attributes;

    attributes.position = position;
    attributes.health = health;
    attributes.damage = damage;
    attributes.symbol = symbol;
    attributes.isAlive = true;

    return attributes;
}