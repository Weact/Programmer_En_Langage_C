#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "prototypes.h"

//GAME METHODS
void print_cursor(tCursor * cursor)
{
    printf("Les coordonnees du curseur sont: [%d;%d].", cursor->cx, cursor->cy);
}

//GAME BOARD
/*
* Functions :   init_base_game_array(char tab_p1[TAILLE][TAILLE], tCursor * cursor);
*               display_base_game_array(char tab_p1[TAILLE][TAILLE], tCursor cursor);
* Descriptions :
*               1st: Init the game board with the WATER SYMBOL.
*               2nd: Fill the game board with symbols.
* Args :
*               1st: bidimensionnal array, pointer of tCursor type
*               2nd: bidimensionnal array, tCursor type
* Output :
*               1st: N/A
*               2nd: Display the board in the console to users.
*/
void init_players_board(player * player1, player * player2)
{
    int i,j;

    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            player1->gameboard[i][j] = '~';
            player2->gameboard[i][j] = '~';
        }
    }
}

void display_player_board(player player, tCursor cursor)
{
    system("cls");
    int i,j;

    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            if((i == cursor.cy) && (j == cursor.cx))
            {
                color(0,9);
            }else{
                color(15,0);
            }
            printf(" %c ", player.gameboard[i][j]);
        }
        color(15,0);
        printf("\n");
    }
}

//CURSOR
void init_cursor(tCursor * ptrCursor)
{
    set_cursor_X(ptrCursor, 0);
    set_cursor_Y(ptrCursor, 0);
}
//BOAT
/*
* Functions :   void boat_description(boat myBoat)
* Descriptions :
*               1st: This function get the name, the size, and the position of the targetted boat to tell user about boat's information
*               2nd: This function place a boat on the board
* Args :
*               1st: boat
*               2nd: gameboard, boat, cursor to place the boat at position, integer : player number, integer : turn number
* Output :
*               1st: tell the user which boat is ready to be placed, his size and his current position
*               2nd: Place the selected boat on the board for the player X according to his turn number
*/
//void boat_description(boat myBoat)
//{
//    printf("Le bateau selectionne est un: %s de taille %d. Sa position: %d;%d.\n", myBoat.name, myBoat.length, myBoat.position.cRow, myBoat.position.cCol);
//}

int count_boat_number(player playerboard)
{
    int boat_number = 0;
    for(int i = 0; i<TAILLE; i++)
    {
        for(int j = 0; j<TAILLE; j++)
        {
            if(playerboard.gameboard[i][j] != '~')
                boat_number++;
        }
    }
    return boat_number;
}

int check_if_player_lost(player * playerlist[], int number_of_player)
{
    int player_lost; //1: True 0: False
    for(int i = 0; i<number_of_player; i++)
    {
        if (playerlist[i]->boat_left_on_board > 0)
            player_lost = 0;
        else
            player_lost = 1;
    }

    return player_lost;
}


//INPUTS MANAGEMENTS
/*
* Functions :   input input_receiver();
*               void input_sender(input inp, tCursor * cursor)
* Descriptions :
*               1st: when the user press a key, the function will check which key he pressed and return it.
*               2nd: this function do the appropriate action according to which input the previous function got.
* Args :
*               1st:
*               2nd: input, pointer of tCursor type
* Output :
*               1st: N/A
*               2nd: Display the board in the console to users.
*/
input input_receiver()
{
    input in = getch();
    switch(in)
    {
    case 27:
        return EXIT;
        break;
    case 90:
    case 122:
        return UP;
        break;
    case 81:
    case 113:
        return LEFT;
        break;
    case 83:
    case 115:
        return DOWN;
        break;
    case 68:
    case 100:
        return RIGHT;
        break;
    case 8:
        return CANCEL;
        break;
    case 13:
        return CONFIRM;
        break;
    case 32:
        return DIR;
        break;
    default:
        break;
    }

}

void input_sender(input inp, tCursor * cursor)
{
    switch(inp)
    {
    case EXIT:
        system("cls");
        color(15,12);
        printf("ESCAPE PRESSED\n");
        printf("EXITING PROGRAM...\n");
        color(15,0);
        exit(0);
        break;
    case CANCEL:
        color(0,14);
        printf("CANCELLED\n");
        color(15,0);
        break;
    case UP:
        if(cursor->cy>0)
            cursor->cy--;
        printf("Z PRESSED: %d.\n", cursor->cy);
        break;
    case LEFT:
        if(cursor->cx>0)
            cursor->cx--;
        printf("Q PRESSED: %d.\n", cursor->cx);
        break;
    case DOWN:
        if(cursor->cy<TAILLE-1)
            cursor->cy++;
        printf("S PRESSED: %d.\n", cursor->cy);
        break;
    case RIGHT:
        if(cursor->cx<TAILLE-1)
            cursor->cx++;
        printf("D PRESSED: %d.\n", cursor->cx);
        break;
    case CONFIRM:
        break;
    default:
        break;
    }

}

ask_playername(player * ptr_player1, player * ptr_player2)
{
    printf("Bonjour Joueur 1\n");
    printf("Entrez votre pseudo\n");
    printf("> ");
    scanf("%s", ptr_player1->name);

    printf("Bonjour Joueur 2\n");
    printf("Entrez votre pseudo\n");
    printf("> ");
    scanf("%s", ptr_player2->name);
}

///// FILE MANAGEMENT /////
void write_score(char name[20], int score)
{
    FILE * ptr_score_binfile = fopen("score.bin", "ab");
    int char_bytesize = sizeof(name[0]) * 20; //give the size of a character to char_bytesize in byte

    if(ptr_score_binfile == NULL)
    {
        printf("Can't open folder\n");
    }else{
        fwrite(name, char_bytesize, 1, ptr_score_binfile);
        fwrite(&score, sizeof(int), 1, ptr_score_binfile);
        fclose(ptr_score_binfile);
    }
}

void display_score(){
    system("cls");

    // Check if the file exists
    if(access("score.bin", F_OK ) != -1){
        FILE* ptr_score_binfile = fopen("score.bin", "rb");
        int score_int;
        char name[20];
        int char_bytesize = sizeof(char) * 20;

        // Read the score file until it reach EOF
        if(ptr_score_binfile != NULL){
            while(2){
                size_t n_name = fread(name, char_bytesize, 1, ptr_score_binfile);
                size_t n_score = fread(&score_int, 4, 1, ptr_score_binfile);
                if (n_name < 1 || n_score < 1) { break; }
                printf("Player: %s | Score: %d\n", name, score_int);
            }
        } else {
            printf("Can't read source file.\n");
        }
    } else { // If the file does not exist
        printf("No score to display\n");
    }

    // Wait for an input to proceed
    printf("Press a button to leave.\n");
    int wait = getch();

    return;
}

//COLOR MODIFIER
/*
* Functions :   color(int t, int f);
* Descriptions :
*               1st: modify the color of the console (background / foreground) when printf, scanf, [...]
* Args :
*               1st: 2 int
* Output :
*               1st: colored output
*/
void color(int t, int f)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,f*16+t);
}

//SETGET METHODS
/*void set_cell_X(cell *ptr, int nNewRow)
{
    ptr->cRow = nNewRow;
}
void set_cell_Y(cell *ptr, int nNewCol)
{
    ptr->cCol = nNewCol;
}
int get_cell_X(cell ptr)
{
    return ptr.cRow;
}
int get_cell_Y(cell ptr)
{
    return ptr.cCol;
}
*/

void set_cursor_X(tCursor *ptr, int nNewX)
{
    ptr->cx = nNewX;
}
void set_cursor_Y(tCursor *ptr, int nNewY)
{
    ptr->cy = nNewY;
}
int get_cursor_X(tCursor ptr)
{
    return ptr.cx;
}
int get_cursor_Y(tCursor ptr)
{
    return ptr.cy;
}
