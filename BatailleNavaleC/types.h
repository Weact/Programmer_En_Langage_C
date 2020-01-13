#include <stdio.h>
#include <stdlib.h>

//CONSTANTS
#define TAILLE 10

typedef enum player_direction_placement{
    HORIZONTAL,
    VERTICAL
}direction;

typedef struct player{
    char name[20];
    char gameboard[TAILLE][TAILLE];
    int score;
    direction dir;
    int boat_left_on_board;
    int lost_game;
}player;

typedef struct cells{
	int cRow;
	int cCol;
}cells;

typedef struct tCursor{
    int cx;
    int cy;
}tCursor;

typedef struct boats{
    char name[18];
    cells position;
    int length;
    int number;
    char symbol;
}boat;

typedef enum inputs{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    DIR,
    CONFIRM,
    CANCEL,
    EXIT
}input;

