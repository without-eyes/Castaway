#include <stdio.h>
#include <ncurses.h>
#include <malloc.h>

typedef struct Player {
    short x;
    short y;
    short health;
} Player;

void initialiseScreen();
void setMap();
Player* initialisePlayer();
void handleInput(unsigned char input, Player* player);
void movePlayer(short y, short x, Player* player);

int main(void) {
    initialiseScreen();
    setMap();
    Player* player = initialisePlayer();

    unsigned char input;
    while ((input = getch()) != 'q') {
        handleInput(input, player);
    }

    getch();
    endwin();
    free(player);
}

void initialiseScreen() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void setMap() {
    for (unsigned char i = 0; i < 40; i++) {
        for (unsigned char j = 0; j < 70; j++) {
            mvprintw(i, j, ".");
        }
    }
}

Player* initialisePlayer() {
    Player * player = (Player*)malloc(sizeof(Player));
    player->x = 0;
    player->y = 0;
    player->health = 100;

    mvprintw(player->y, player->x, "@");
    move(player->y, player->x);

    return player;
}

void handleInput(unsigned char input, Player* player) {
    switch (input) {
        case 'W':
        case 'w':
            movePlayer(player->y - 1, player->x, player);
            break;

        case 'A':
        case 'a':
            movePlayer(player->y, player->x - 1, player);
            break;

        case 'S':
        case 's':
            movePlayer(player->y + 1, player->x, player);
            break;

        case 'D':
        case 'd':
            movePlayer(player->y, player->x + 1, player);
            break;

        default: break;
    }
}

void movePlayer(short y, short x, Player* player) {
    if (mvinch(y, x) == '.') {
        mvprintw(player->y, player->x, ".");
        mvprintw(y, x, "@");
        move(y, x);
        player->y = y;
        player->x = x;
    }
}
