#include "../../include/core/attributes.h"

Attributes initializeEntity(Position position, int health, int damage, char symbol) {
    Attributes attributes;

    attributes.position = position;
    attributes.health = health;
    attributes.damage = damage;
    attributes.symbol = symbol;
    attributes.isAlive = true;

    return attributes;
}