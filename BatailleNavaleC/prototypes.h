#include <stdio.h>
#include <stdlib.h>
#include "types.h"

//METHODS PROTOTYPES
void init_players_board(player * player1, player * player2);
void display_player_board(player player, tCursor cursor);
void init_cursor(tCursor * cursor);
//void createCase(int r, int c, cell cl);
input input_receiver();
void input_sender(input inp, tCursor * cursor);
void print_cursor(tCursor * cursor);
//void boat_description(boat myBoat);
int count_boat_number(player playerboard);
int check_if_player_lost(player * playerlist[], int number_of_player);
ask_playername(player * ptr_player1, player * ptr_player2);

///// SCORE MANAGEMENT /////
void write_score(char name[20], int score);

//COLOR METHOD
void color(int t, int f); //FONCTION POUR LES COULEUR
/*COLOR CODE
1st: fgcolor
2nd: bgcolor
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc*/


//SETGET PROTOTYPES
//void set_cell_X(cell *ptr, int nNewRow);
//void set_cell_Y(cell *ptr, int nNewCol);
//int get_cell_X(cell ptr);
//int get_cell_Y(cell ptr);

void set_cursor_X(tCursor *ptr, int nNewX);
void set_cursor_Y(tCursor *ptr, int nNewY);
int get_cursor_X(tCursor ptr);
int get_cursor_Y(tCursor ptr);
