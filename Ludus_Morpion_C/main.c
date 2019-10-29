#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 3

//TYPEDEF
//On créer notre propre variable comme les "types structurées" vu en ALGO (C # ALGO)
typedef enum {VIDE = 1, CROIX, ROND} Jeu; //INITIALISATION DE VIDE A 1 --> CROIX = 2 --> ROND = 3
typedef enum {FALSE, TRUE} Boolean; //CREATION D'UN TYPE BOOLEAN POUVANT CONTENIR FALSE OU TRUE UNIQUEMENT. BUT : Faciliter la suite du programme

//PROTOTYPES
Jeu j_TabMorpion[TAILLE][TAILLE]; //Création d'un tableau pouvant contenir uniquement les valeurs VIDE, CROIX ou ROND (1, 2, 3).
void init_TabMorpion();
void disp_TabMorpion();
void j_JouerTour();


//VARIABLES
int j_TourJoueur = CROIX;
int n_Joueur = 1;
//MAIN
int main()
{
    printf("--------- JEU DU MORPION ---------\n");
    printf("Le joueur 1 aura le symbole : X\n");
    printf("Le joueur 2 aura le symbole : O\n");
    printf("--------- JEU DU MORPION ---------\n");
    init_TabMorpion();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    j_JouerTour();
    disp_TabMorpion();
    return 0;
}

//DECLARATION DES FONCTIONS
void init_TabMorpion()
{
    int i, j;

    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            j_TabMorpion[i][j] = VIDE;
        }
    }

}

void disp_TabMorpion()
{
    int i, j;;

    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            switch(j_TabMorpion[i][j])
            {
            case VIDE:
                printf("~ ");
                break;
            case CROIX:
                printf("X ");
                break;
            case ROND:
                printf("O ");
                break;
            }
        }
        printf("\n");
    }
}

void j_JouerTour()
{
    int n_ligne, n_colonne;
    Boolean coordonnees = FALSE;
    printf("JOUEUR %d\n", n_Joueur);
    do{
        printf("Coordonnees de votre placement : [LIGNE | COLONNE]\n");
        scanf("%d %d", &n_ligne, &n_colonne);
        printf("\n");

        if ((n_ligne > 0) && (n_ligne <= TAILLE) && (n_colonne > 0) && (n_colonne <= TAILLE))
        {
            n_ligne--;
            n_colonne--;

            if(j_TabMorpion[n_ligne][n_colonne] != VIDE)
            {
                printf("Case occupee, recommencez.\n");
            }else{
                coordonnees = TRUE;
                j_TabMorpion[n_ligne][n_colonne] = j_TourJoueur;
                if(j_TourJoueur == CROIX)
                    j_TourJoueur = ROND;
                else
                    j_TourJoueur = CROIX;

                if(n_Joueur == 1)
                    n_Joueur = 2;
                else
                    n_Joueur = 1;
            }
        }else{
            printf("Saisie incorrecte, veuillez recommencez. [RAPPEL : 1 >= saisie <= 3]\n");
        }
    }while(coordonnees != TRUE);
}

/* NOMBRE ALEATOIRE
int n_randomNumber(int n_min, int n_max);

int n_randomNumber(int n_min, int n_max)
{
    int n_random = (rand() % (n_max - n_min + 1)) + n_min;

    return n_random;
}
*/
