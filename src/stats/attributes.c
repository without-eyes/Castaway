#include "../../include/stats/attributes.h"

Attributes initializeAttributes(const int health, const int damage, const chtype symbol) {
    Attributes attributes;

    attributes.health = health;
    attributes.damage = damage;
    attributes.symbol = symbol;

    return attributes;
}

inline bool isAlive(const Attributes entityAttributes) {
    return entityAttributes.health > 0;
}