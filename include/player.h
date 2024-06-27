#ifndef CASTAWAY_PLAYER_H
#define CASTAWAY_PLAYER_H

typedef struct Player {
    short x;
    short y;
    short health;
    short damage;
} Player;

Player* initialisePlayer();
void handleInput(unsigned char input, const Player* player);
void movePlayer(short y, short x, Player* player);

#endif //CASTAWAY_PLAYER_H
