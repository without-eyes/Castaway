#include "../../include/entities/attributes.h"

Attributes initializeEntity(Position position, short health, short damage, char symbol) {
    Attributes attributes;

    attributes.position = position;
    attributes.health = health;
    attributes. damage = damage;
    attributes.symbol = symbol;

    return attributes;
}