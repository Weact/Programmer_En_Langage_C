#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include "functions.h"

int main()
{
    player player1;
    player player2;
    player *pPlayer1, *pPlayer2;
    pPlayer1 = &player1;
    pPlayer2 = &player2;

    player * player_list[2] = {pPlayer1, pPlayer2};
    player * pCurrentPlayer = player_list[0];
    int number_of_player = sizeof(player_list) / sizeof(player_list[0]);

    tCursor mainCursor;
    tCursor *ptrCursor = &mainCursor;

    boat porteavion = {"Porte-Avion", {0,0}, 5, 1, 'V'};
    boat croiseur = {"Croiseur", {0,0}, 4, 1, 'C'};
    boat contretorpilleur = {"Contre-Torpilleur", {0,0}, 3, 2, 'W'};
    boat torpilleur = {"Torpilleur", {0,0}, 2, 1, 'T'};
    boat *ptrPorteavion = &porteavion;
    boat *ptrCroiseur = &croiseur;
    boat *ptrContretorpilleur = &contretorpilleur;
    boat *ptrTorpilleur = &torpilleur;

    boat boat_list[4] = {porteavion, croiseur, contretorpilleur, torpilleur};
    int boat_index = 0;
    boat * ptrcurrent_boat;
    int boatarray_size = sizeof(boat_list) / sizeof(boat_list[0]);

    init_players_board(pPlayer1, pPlayer2);
    init_cursor(ptrCursor);

    player1.score = 0;
    player2.score = 0;
    ask_playername(pPlayer1, pPlayer2);

    //print_cursor(ptrCursor);
    for(int p = 0; p<number_of_player; p++)
    {
        system("cls");
        pCurrentPlayer = player_list[p];
        pCurrentPlayer->dir = HORIZONTAL;
        printf("%s", pCurrentPlayer->name);
        boat_index = 0;
        ptrPorteavion->number=1;
        ptrCroiseur->number=1;
        ptrContretorpilleur->number=2;
        ptrTorpilleur->number=1;
        //boucle a travers la liste des bateaux
        while(boat_index<boatarray_size)
        {
            ptrcurrent_boat = &boat_list[boat_index];
            int boat_nb_exemplaire = ptrcurrent_boat->number;
            //boucle a travers les exemplaires
            while(boat_nb_exemplaire != 0)
            {
                input inp = input_receiver();
                input_sender(inp, ptrCursor);
                if(inp == CONFIRM) //For this function, we assume that the player enter a valid position. We do not check if the entered position is correct or incorrect.
                {
                    //Loop to update board according to the appropriated boat
                    for(int i = 0; i<ptrcurrent_boat->length; i++)
                    {
                        if(pCurrentPlayer->dir == HORIZONTAL)
                            pCurrentPlayer->gameboard[mainCursor.cy][mainCursor.cx+i] = ptrcurrent_boat->symbol;
                        else
                            pCurrentPlayer->gameboard[mainCursor.cy+i][mainCursor.cx] = ptrcurrent_boat->symbol;
                    }
                    boat_nb_exemplaire--;

                }
                else if(inp == DIR)
                {
                    if(pCurrentPlayer->dir == HORIZONTAL)
                        pCurrentPlayer->dir = VERTICAL;
                    else
                        pCurrentPlayer->dir = HORIZONTAL;
                }
                display_player_board(*pCurrentPlayer, mainCursor);
            }
        boat_index++;

        }
    }
    //END OF PREPARATION PHASE

    //SHOOTING PHASE
    system("cls");
    player1.boat_left_on_board = count_boat_number(player1);
    player2.boat_left_on_board = count_boat_number(player2);
    int defender = 0;
    int attacker = 0;
    int is_attack_valid; // - 0 False/1 True - Act as a bool. If false : ask player to enter 2 int as coordinate. If true : Player has entered valid coordinate.
    while(check_if_player_lost(player_list, number_of_player) == 0)
    {
        for(int p_turn = 0; p_turn<number_of_player; p_turn++)
        {
            if(p_turn == 0)
            {
                defender = 1;
                attacker = 0;
            }
            else
            {
                defender = 0;
                attacker = 1;
            }

            is_attack_valid = 0;
            int column_to_attack;
            int row_to_attack;

            printf("%s, entrez les coordonnees a attaquer [1-10].\n", player_list[attacker]->name);
            while(!is_attack_valid)
            {
                do{
                    printf("Column(x) > ");
                    scanf("%d", &column_to_attack);
                    printf("Row(y) > ");
                    scanf("%d", &row_to_attack);
                }while( (column_to_attack < 1  || column_to_attack > 10) && (row_to_attack < 1 || row_to_attack > 10) );
                is_attack_valid = 1;
            }
            printf("Le joueur %s attaque [X:%d;Y:%d]\n", player_list[attacker]->name, column_to_attack, row_to_attack);
            printf("Contenu de la case [X:%d;Y:%d]: %c\n", column_to_attack, row_to_attack, player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1]);
            printf("Verification si un bateau a ete touche...\n");

            if(player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1] != '~' && player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1] != 'X' &&  player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1] != 'O' )
            {
                player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1] = 'X';
                player_list[defender]->boat_left_on_board--;
                player_list[attacker]->score++;
            }else{
                if(player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1] != 'X')
                    player_list[defender]->gameboard[row_to_attack-1][column_to_attack-1] = 'O';
                    if(player_list[attacker]->score > 0)
                        player_list[attacker]->score--;
            }

            printf("Boat left for %s: %d\n", player1.name, player1.boat_left_on_board);
            printf("Boat left for %s: %d\n", player2.name, player2.boat_left_on_board);
            int wait = getch();
            display_player_board(*player_list[defender], mainCursor);
        }
    }
    int player_won = 0;

    switch(player_list[0]->lost_game)
    {
    case 0:
        player_won = 1;
        break;
    case 1:
        player_won = 0;
        break;
    }

    printf("Le joueur %d a gagne la partie !\n", player_won+1);
    printf("==========AFFICHAGE DES SCORES==========");
    printf("> %s: %d points\n", player1.name, player1.score);
    printf("> %s: %d points\n", player2.name, player2.score);

    write_score(player1.name, player1.score);
    write_score(player2.name, player2.score);
    display_score();
    return 0;
}
