#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>

/*
*   DRUCKES LUCAS
*   LUDUS ACADEMIE 2019-2020
*   TUESDAY 26 NOVEMBER 2019
*   MASTERMIND-LIKE GAME
*   ////TOUT COMMENTAIRE EST TRACE DE DEBUG (normalement)////
*   https://github.com/Weact
*/

#define MIN 0
#define MAX 9
#define TABSIZE 4

//DEFINITION DES TYPE STRUCTURES
typedef enum {RIGHT, WRONG, WRONGPLACE, EMPTY} Position;
typedef enum {VRAI, FAUX} Boolean;

//PROTOTYPES DES FONCTIONS
void initTab(int *n_tabGame);
void displayTab(int *n_tabGame);
void displayTabUser(int *n_tabUser);
void askTabUser(int *n_tabUser);
void checkTabs(int *n_tabMastermind, int *n_tabGameUser, Position *pos_checkTab);
void displayTotalTab(int *n_tabMastermind, int *n_tabGameUser, Position *pos_checkTab);
void color(int t, int f);
bool checkVictory(Position *pos_checkTabVictory);
bool confirm(int c);

//FONCTION MAIN
int main()
{
    srand(time(NULL)); //Initialisation du random
    //GenerateInteger();

    int n_tries = 12; //Nombre d'essai = Nombre de Chiffre * 3 (pour 4 chiffre : 12 essai)

    int n_TabMastermind[TABSIZE]; //TABLEAU DU JEU, 4 CHIFFRES GENERES ALEATOIREMENT
    int n_TabUser[TABSIZE]; //TABLEAU UTILISATEUR, 4 CHIFFRE A RENSEIGNER
    Position pos_checkPos[TABSIZE]; //TABLEAU POUR VERIFIER SI LES CHIFFRES SONT BIEN PLACES OU NON, OU S'ILS SONT FAUX

    initTab(n_TabMastermind); //ON GENERE LE TABLEAU DU JEU MASTERMIND
    //displayTab(n_TabMastermind); DEBUG FUNCTION
    do{
        color(15,1);
        printf("\n[ESSAI.S RESTANT.S]: %d\n\n", n_tries);
        color(15,0);
        askTabUser(n_TabUser); //ON DEMANDE A L'UTILISATEUR DE RENTRER LES CHIFFRES
        checkTabs(n_TabMastermind, n_TabUser, pos_checkPos); //ON VERIFIE SES ENTREES PAR RAPPORT AU TABLEAU DU JEU
        displayTotalTab(n_TabMastermind, n_TabUser, pos_checkPos); //ON AFFICHE SES VALEURS ET S'IL A JUSTE, PRESQUE, OU FAUX
        n_tries--; //ON ENLEVE 1 ESSAI
        color(15,15); printf("\n----------------------------------------------------------------------------------------\n"); color(15,0); //SEPARATION D'ESSAI
    }while(checkVictory(pos_checkPos) != true && n_tries > 0); //ON REPETE LE JEU TANT QU'IL N'A PAS GAGNE OU QU'IL N'A PAS PERDU


    if(checkVictory(pos_checkPos) == true) //SI IL A GAGNE, DONC SI IL A REUSSI A SORTIR DE LA BOUCLE (=soit gagner soit perdu)
    {
        system("cls"); //ON CLEAR LA CONSOLE
        color(15,10);
        printf("\nFELICIATION ! VOUS AVEZ GAGNE ! ESSAI.S RESTANT.S: %d\n", n_tries);
        printf("\nLE NUMERO ETAIT: ");
        displayTab(n_TabMastermind); //ON AFFICHE LE TABLEAU DU JEU MASTERMIND
        printf("ET VOUS AVEZ REUSSI AVEC LES CHIFFRES: ");
        printf("%d%d%d%d", n_TabUser[0], n_TabUser[1], n_TabUser[2], n_TabUser[3]); //ON AFFICHAGE LES VALEURS DU JOUEUR DANS SON TABLEAU
        printf(". BRAVO !\n");
        color(15,0);
    }else{ //SINON S'IL A PERDU (donc checkVictory A ETE MIS A FALSE CAR NOMBRE D'ESSAI = 0
        system("cls"); //ON CLEAR LA CONSOLE
        color(15,12);
        printf("\nDOMMAGE ! VOUS AVEZ PERDU.\n");
        printf("\nLE NUM ETAIT: ");
        displayTab(n_TabMastermind); //ON AFFICHE LES CHIFFRES QUE LE JOUEUR DEVAIT TROUVER
        printf("MERCI D'AVOIR JOUE !\n");
        color(15,0);
    }

    return 0;
}

void initTab(int *n_tabGame) //FONCTION GENERATION DU TABLEAU MASTERMIND --- DOUBLON ACCEPTE
{
    int i;
    for(i = 0; i < TABSIZE; i++)
    {
        n_tabGame[i] = rand()%10;
    }
}

void displayTab(int *n_tabGame) //DEBUG FONCTION POUR AFFICHER LE NOMBRE MASTERMIND DANS LA CONSOLE [NON UTILISE POUR LE JEU]
{
    int i;
    printf("Nombre Mastermind: ");
    for(i = 0; i < TABSIZE; i++)
    {
        printf("%d", n_tabGame[i]);
    }
    printf("\n");
}

void displayTabUser(int *n_tabUser) //FONCTION POUR AFFICHER LES CHIFFRES DE L'UTILISATEUR
{
    int x;
    printf("Vos valeurs: ");
    for(x=0; x<TABSIZE; x++)
    {
        printf(" %d", n_tabUser[x]);
    }
}

void askTabUser(int *n_tabUser) //DEMANDE A L'UTILISATEUR D'ENTRER LES CHIFFRES
{
    int i, c, n_temp; //I SERA LA VARIABLE POUR LA BOUCLE FOR ; C SERA LA VARIALBE POUR CONFIRMER LA SAISIE DE L'UTILISATEUR ; N_TEMP SERA LE CHIFFRE DU JOUEUR A ENTRER
    Boolean verif = FAUX;
    printf("Entrez %d nombres entre 0 et 9 l'un apres l'autre: \n\n", TABSIZE);

    do
    {
       for(i=0; i<TABSIZE; i++)
        {
            //printf("[I]: %d\n", i);
            do
            {

                color(14,5);
                n_temp = getch()-48; //ON RECUPERE LA VALEUR DU JOUEUR EN CARACTERE ET ON SOUSTRAIT 48 POUR AVOIR LA VALEUR EN ENTIER
                color(15,0);
                //fflush(stdin);

                if(n_temp >= 0 && n_temp <= 9) //SI L'ENTREE JOUEUR EST ENTRE 0 ET 9
                {
                    verif = VRAI; //ALORS CEST OK
                    color(2,7);
                    printf("[%d]: %d.", i+1, n_temp); //ON AFFICHE L'IDENTIFIANT DE LA VALEUR (i) ET LE CHIFFRE
                    printf("OK\n");
                    color(15,0);
                    n_tabUser[i] = n_temp; //ON INSERE APRES VERIFICATION, LE CHIFFRE DANS LE TABLEAU DU JOUEUR
                }else
                {
                    verif = FAUX; //L'ENTREE JOUEUR EST INFERIEUR OU SUPERIEUR A 0/9 DONC ON FAIT RIEN
                    /*color(12,7);
                    printf("ERROR\n");
                    color(15,0);*/
                }
            }while(verif != VRAI); //ET ON REPETE DANS QUE VERIF SOIT EGAL A VRAI POUR AVOIR UNE SAISIE CORRECT



        }
            //UNE FOIS LES 4 SAISIES CORRECTES, ON DEMANDE A L'UTILISATEUR SI IL VEUT VALIDER, AU CAS OU UN MISTYPE AURAIT EU LIEU
        printf("\nConfirmez-vous votre saisie ? OUI[1] / NON[0]. Voici vos valeurs: ");
        displayTabUser(n_tabUser); printf("\n"); //ON LUI RE AFFICHE SA SAISIE
        do{
                c = getch()-48; //PAREIL QUE POUR N_TEMP
        }while(c != 0 && c != 1); //ON REPETE TANT QUE L'ENTREE UTILISATEUR POUR (c) N'EST PAS EGAL A 0 OU 1 (1 pour Oui, 0 pour Non)

    }while(!confirm(c)); //ON REPETE TOUTE LA BOUCLE DE DEMANDE DE SAISIE TANT QUE L'UTILISATEUR NE CONFIRME PAS SA SAISIE

        //WAS FOR DEBUGGING
/*color(15,10);
        printf("\n[---VOS VALEURS---]: ");
        for(int e = 0; e<TABSIZE; e++)
            printf("%d", n_tabUser[e]);
color(15,0);*/



}

void checkTabs(int *n_tabMastermind, int *n_tabGameUser, Position *pos_checkTab) //FONCTION DE VERIFICATION DE LA POSITION DU CHIFFRE JOUEUR PAR RAPPORT AU TABLEAU MASTERMIND
{
    int i, j;

    for(i=0; i<TABSIZE; i++)
    {
        pos_checkTab[i] = EMPTY; //ON INITIALISE LA POSITION DU TABLEAU A L'INDEX PAR LA POSITION [EMPTY]
        if(n_tabGameUser[i] == n_tabMastermind[i]) //SI LE CHIFFRE UTILISATEUR = CHIFFRE MASTERMIND A LA MEME POSITION
        {
            pos_checkTab[i] = RIGHT; //POSITION = RIGHT (bien placé et juste)
        }
        else //SINON SI CEST PAS JUSTE
        {
            for(j=0; j<TABSIZE; j++)
            {
                if(n_tabGameUser[i] == n_tabMastermind[j] && n_tabGameUser[j] != n_tabMastermind[j]) //SI LE CHIFFRE UTILISATEUR EST JUSTE MAIS MAL PLACE ET QUE LE CHIFFRE UTILISATEUR EST DIFFERENT DU TABLEAU MASTER A LA POSITION [J]
                {
                    pos_checkTab[i] = WRONGPLACE; //ON INDIQUE QUE LE CHIFFRE EST MAL PLACE
                }

            }
            if(pos_checkTab[i] == EMPTY) //ENFIN, SI UNE CASE DU TABLEAU RESTE "EMPTY" (c'est a dire: qui n'est pas vrai ou qui n'est pas juste "mal place")
            {
                pos_checkTab[i] = WRONG; //ON INDIQUE QUE LE CHIFFRE EST FAUX
            }
        }

        //printf("\n[INDEX]: %d / [VALEUR]: %d/%d\n", i, n_tabGameUser[i], n_tabMastermind[i]);
    }
}

void displayTotalTab(int *n_tabMastermind, int *n_tabGameUser, Position *pos_checkTab) //FONCTION D'AFFICHAGE DES VALEURS UTILISATEURS AINSI QUE SON RESULTAT (juste, mal place, faux --> indication avec couleur)
{

    //system("cls");
    /*printf("\n[DEBUG]Vos valeurs: ");
    for(int j = 0; j<TABSIZE; j++) //Debug : Affichage des valeurs du tableau
    {
        printf("%d ", n_tabGameUser[j]);

    }
    //printf("\n[DEBUG]Mastermind: "); //Debug : Affichage des valeurs du mastermind
    for(int f = 0; f<TABSIZE; f++)
    {
        printf("%d ", n_tabMastermind[f]);
    }*/
    //displayTab(n_tabMastermind);
    //switch position si right = vert si wrong = rouge si wrongplace = orange

    printf("\nVos valeurs : ");
    for(int i = 0; i<TABSIZE; i++)
    {
        switch(pos_checkTab[i]) //VERIFICATION DES STATUS
        {
        case RIGHT: //SI LA CASE DU TABLEAU A LA POSITION [I] EST "JUSTE" : ON COLORE EN FOREGROUND BLANC;BACKGROUND VERT
            color(15,2);
            break;
        case WRONGPLACE: //SI LA CASE DU TABLEAU A LA POSITION [I] EST "MAL PLACE" : ON COLORE EN FOREGROUND BLANC;BACKGROUND BLEU
            color(15,9);
            break;
        case WRONG: //SI LA CASE DU TABLEAU A LA POSITION [I] EST "FAUX" : ON COLORE EN FOREGROUND BLANC;BACKGROUND ROUGE
            color(15,12);
            break;
        default:
            color(15,0);
            break;
        }
        printf("%d", n_tabGameUser[i]); //PUIS ON AFFICHE SON CHIFFRE
        color(15,0);
    } //REPETITION DE LA BOUCLE (incrémentation de i) AFIN D' AFFICHER TOUT LE TABLEAU
    printf("\n");
}

bool checkVictory(Position *pos_checkTabVictory) //FONCTION POUR VERIFIER SI LE JOUEUR A GAGNER OU NON
{
    int i;
    int compteur = 0; //VARIABLE POUR VERIFIER COMBIEN DE CHIFFRE SONT VRAI
    for(i=0; i<TABSIZE; i++)
    {
        if(pos_checkTabVictory[i] == RIGHT) //SI LA VALEUR DE LA CASE DU TABLEAU A LA POSITION [I] EST "RIGHT(juste)" :
        {
            compteur++; //ON INCREMENTE LE COMPTEUR
        }
    }

    if(compteur == TABSIZE) //SI LE COMPTEUR EST EGAL A LA TAILLE DU TABLEAU (-> le jeu peut être totalement dynamique !!!!)
    {
        return true; //ON RETOURNE LA VALEUR VRAI(TRUE)
    }
    else{
        return false; //RETOURNE FALSE
    }
}

bool confirm(int c) //FONCTION POUR CONFIRMER LA SAISIE DE L'UTILISATEUR APRES LA DEMANDE
{
    if(c == 1) //SI SAISIE = 1 ALORS IL CONFIRME
        return true;
    if(c == 0) //SI SAISIE = 0 ALORS IL ANNULE ET SOUHAITE RE SAISIR LES VALEURS
    {
        color(15,13);
        printf("[Saisie Annulee, veuillez reecrire les 4 chiffres.]\n");
        color(15,0);
        return false;
    }

    return 0;
}

void color(int t, int f) //FONCTION POUR LES COULEUR
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,f*16+t);
}

//Fonction test du Random()
void GenerateInteger()
{
    int a, i;
    for(i=0; i<=99; i++)
    {
        a = rand() % 10;
        if( i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d ", a);
    }
    printf("\n");
}
