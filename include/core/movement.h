#ifndef CASTAWAY_MOVEMENT_H
#define CASTAWAY_MOVEMENT_H

#include "position.h"
#include "../entities/entities.h"

void moveEntity(Position newPosition, Position *entityPosition, char entitySymbol);

void moveAllEntities(Entities *entities);

#endif //CASTAWAY_MOVEMENT_H
