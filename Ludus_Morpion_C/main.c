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
Boolean j_FinJeu();

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

    do{
        j_JouerTour();
        disp_TabMorpion();
    }while((!j_FinJeu()));

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
    printf("\n");
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
            //Vu qu'un tableau comment à l'index 0, on soustrait 1 aux deux valeurs entrées pour
            //correspondre aux coordonnées du tableau. Exemple : 2 2 sur le tableau sera en realité 3 3,
            //mais grâce à ces lignes, nous pouvons faire en sorte que l'utilisateur puisse
            //écrire 3 3, le programme va donc soutraire 1 aux deux valeurs pour avoir 2 2, et afficher
            //le symbole de l'utilisateur là où il le voulait.
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

Boolean j_FinJeu()
/*
*   BUT : Savoir si un joueur a gagné, ou si le jeu est rempli de pion > Annoncé le gagnant
*   ENTREE : Vérification des cases par rapport à la case du milieu [2][2] ; à la case en haut à gauche [1][1], et à la case en bas à droite [3][3]
*   SORTIE : Victoire ou Nul
*/
{
    int i, j;
    int Gagnant;
    Boolean jeuFini = FALSE;
    //Etape 1 : Vérifier si la case du milieu n'est pas VIDE afin de vérifier les Diagonales ainsi que l'horizontale et la verticale à partir de ce point
    if(j_TabMorpion[2-1][2-1] != VIDE)
    {
        if(
            /* --- */ ( (j_TabMorpion[2-1][1-1] == j_TabMorpion[2-1][2-1]) && (j_TabMorpion[2-1][2-1] == j_TabMorpion[2-1][3-1]) ) ||
            /*  |  */ ( (j_TabMorpion[1-1][2-1] == j_TabMorpion[2-1][2-1]) && (j_TabMorpion[2-1][2-1] == j_TabMorpion[3-1][2-1]) ) ||
            /* diago */ ( (j_TabMorpion[1-1][1-1] == j_TabMorpion[2-1][2-1]) && (j_TabMorpion[2-1][2-1] == j_TabMorpion[3-1][3-1]) ) ||
            /* diago 2 */ ( (j_TabMorpion[1-1][3-1] == j_TabMorpion[2-1][2-1]) && (j_TabMorpion[2-1][2-1] == j_TabMorpion[3-1][1-1]) )
        ){
            Gagnant = j_TabMorpion[2-1][2-1];
            jeuFini = TRUE;
        }
    }

    //Etape 2 : Vérifier si la case en haut a gauche n'est pas VIDE afin de vérifier la première ligne ainsi que la première colonne
    if( (jeuFini == FALSE) && (j_TabMorpion[1-1][1-1] != VIDE) )
    {
        if(
           /* --- */ ( (j_TabMorpion[1-1][1-1] == j_TabMorpion[1-1][2-1]) && (j_TabMorpion[1-1][2-1] == j_TabMorpion[1-1][3-1]) ) ||
           /*  |  */ ( (j_TabMorpion[1-1][1-1] == j_TabMorpion[2-1][1-1]) && (j_TabMorpion[2-1][1-1] == j_TabMorpion[3-1][1-1]) )
        ){
            Gagnant = j_TabMorpion[1-1][1-1];
            jeuFini = TRUE;
        }
    }

    //Etape 3 : Vérifier si la case en bas a droite n'est pas VIDE afin de vérifier la première ligne ainsi que la première colonne
    if( (jeuFini == FALSE) && (j_TabMorpion[3-1][3-1] != VIDE) )
    {
        if(
           /* --- */ ( (j_TabMorpion[3-1][3-1] == j_TabMorpion[3-1][2-1]) && (j_TabMorpion[3-1][2-1] == j_TabMorpion[3-1][1-1]) ) ||
           /*  |  */ ( (j_TabMorpion[3-1][3-1] == j_TabMorpion[2-1][3-1]) && (j_TabMorpion[2-1][3-1] == j_TabMorpion[1-1][3-1]) )
        ){
            Gagnant = j_TabMorpion[3-1][3-1];
            jeuFini = TRUE;
        }
    }

    //Etape 4 : Aannoncer le gagnant si jeuFini est vrai
    if(jeuFini)
    {
        if(Gagnant == CROIX)
        {
            printf("Le joueur possedant la Croix [X] gagne !\n");
        }else{
            printf("Le joueur possedant le Rond [O] gagne !\n");
        }

        return TRUE;
    }

    //Etape 5 : On test si le jeu est rempli ou non. Si oui, alors on retourne FAUX et on arrête le jeu sur un Match Nul. Sinon, on continue.
    for(i = 0; i<TAILLE; i++)
    {
        for(j = 0; j<TAILLE; j++)
        {
            if(j_TabMorpion[i-1][j-1] == VIDE;
            {
                printf("MATCH NUL !");
                return FALSE;
            }
        }
    }

    return TRUE;
}

/* NOMBRE ALEATOIRE
int n_randomNumber(int n_min, int n_max);

int n_randomNumber(int n_min, int n_max)
{
    int n_random = (rand() % (n_max - n_min + 1)) + n_min;

    return n_random;
}
*/
