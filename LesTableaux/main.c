#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10

//Prototypes
//Premier tableau
void InitialisationTableau(int n_matriceEntier[TAILLE][TAILLE], int n_value);
void AffichageTableau(int n_matriceEntier[TAILLE][TAILLE]);
//Deuxieme tableau
void InitialisationTableauDeux(int n_matriceEntierDeux[TAILLE][TAILLE], int n_valueB);
void AffichageTableauDeux(int n_matriceEntierDeux[TAILLE][TAILLE]);
//somme de chaque tableaux
int n_sommeMatrice(int n_matriceEntier[TAILLE][TAILLE]);
int n_sommeMatriceDeux(int n_matriceEntierDeux[TAILLE][TAILLE]);
//Addition de la somme des deux tableaux
int n_AdditionerMatrices(int n_firstMatrice[TAILLE][TAILLE], int n_secondMatrice[TAILLE][TAILLE]);
//Generateur de nombre aléatoire
int n_randomNumber(int n_min, int n_max);


//Les tableaux 2 dimensions et procedures
int main()
{
    srand(time(NULL)); //INIT TIME EVERY MAIN() EXECUTION

	//Tableaux 2dim d'entier
	int n_matriceEntier[TAILLE][TAILLE]; //TAB ONE
	int n_matriceEntierDeux[TAILLE][TAILLE]; //TAB TXO

	InitialisationTableau(n_matriceEntier, n_randomNumber(0,9));
	AffichageTableau(n_matriceEntier);
	printf("\n");
	InitialisationTableauDeux(n_matriceEntierDeux, n_randomNumber(0,9));
	AffichageTableauDeux(n_matriceEntierDeux);
    printf("\n");
	int n_resSommeMatrice = n_sommeMatrice(n_matriceEntier);
	printf("Resultat de la somme de notre matrice : %d\n", n_resSommeMatrice);
	int n_resSommeMatriceDeux = n_sommeMatriceDeux(n_matriceEntierDeux);
	printf("Resultat de la somme de notre matrice deux : %d\n", n_resSommeMatriceDeux);
	int n_resTotalMatrice = n_AdditionerMatrices(n_matriceEntier, n_matriceEntierDeux);
	printf("Resultat de la somme de nos deux matrices : %d\n", n_resTotalMatrice);

	return 0;
}

void InitialisationTableau(int n_matriceEntier[TAILLE][TAILLE], int n_value)
//Initialisation du tableau.
{
	int n_i, n_j;

	//Initialisation de la matrice
	for (n_i=0; n_i<TAILLE; n_i++)
	{
		for (n_j=0; n_j<TAILLE; n_j++)
		{
			n_matriceEntier[n_i][n_j] = n_value;
		}
	}
}


void AffichageTableau(int n_matriceEntier[TAILLE][TAILLE])
//Affichage du tableau
{
	int n_i, n_j;

    for (n_i=0; n_i<TAILLE; n_i++)
	{
		for (n_j=0; n_j<TAILLE; n_j++)
		{
			printf("%3d", n_matriceEntier[n_i][n_j]);
		}
		printf("\n");
	}
}

int n_sommeMatrice(int n_matriceEntier[TAILLE][TAILLE])
{
	int n_resSommeMatrice = 0;
	int n_i, n_j;

    for (n_i=0; n_i<TAILLE; n_i++)
	{
		for (n_j=0; n_j<TAILLE; n_j++)
		{
			n_resSommeMatrice += n_matriceEntier[n_i][n_j];
		}
	}

	return (n_resSommeMatrice);
}

int n_randomNumber(int n_min, int n_max)
{
    int n_random = (rand() % (n_max - n_min + 1)) + n_min;

    return n_random;
}

void InitialisationTableauDeux(int n_matriceEntierDeux[TAILLE][TAILLE], int n_valueB)
{
	int n_i, n_j;

	//Initialisation de la matrice
	for (n_i=0; n_i<TAILLE; n_i++)
	{
		for (n_j=0; n_j<TAILLE; n_j++)
		{
			n_matriceEntierDeux[n_i][n_j] = n_valueB;
		}
	}
}

void AffichageTableauDeux(int n_matriceEntierDeux[TAILLE][TAILLE])
{
	int n_i, n_j;

    for (n_i=0; n_i<TAILLE; n_i++)
	{
		for (n_j=0; n_j<TAILLE; n_j++)
		{
			printf("%3d", n_matriceEntierDeux[n_i][n_j]);
		}
		printf("\n");
	}
}

int n_sommeMatriceDeux(int n_matriceEntierDeux[TAILLE][TAILLE])
{
	int n_resSommeMatriceDeux = 0;
	int n_i, n_j;

    for (n_i=0; n_i<TAILLE; n_i++)
	{
		for (n_j=0; n_j<TAILLE; n_j++)
		{
			n_resSommeMatriceDeux += n_matriceEntierDeux[n_i][n_j];
		}
	}

	return (n_resSommeMatriceDeux);
}

int n_AdditionerMatrices(int n_firstMatrice[TAILLE][TAILLE], int n_secondMatrice[TAILLE][TAILLE])
{
    //int n_resSommeTabUn = 0;
    //int n_resSommeTabDeux = 0;
    int n_resSommeTotal = 0;
    int n_i, n_j;

    for(n_i = 0; n_i<TAILLE; n_i++)
    {
        for(n_j = 0; n_j<TAILLE; n_j++)
        {
           //n_resSommeTabUn += n_firstMatrice[n_i][n_j];
           //n_resSommeTabDeux += n_secondMatrice[n_i][n_j];
           n_resSommeTotal = n_sommeMatrice(n_firstMatrice) + n_sommeMatriceDeux(n_secondMatrice);
        }
    }

    //n_resSommeTotal = n_resSommeTabUn + n_resSommeTabDeux;

    return (n_resSommeTotal);
}
