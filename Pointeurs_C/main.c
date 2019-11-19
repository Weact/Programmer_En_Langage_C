#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 5

int sommeEntiers(int, int);
void somEntiers(int, int, int *);

//LES POINTEURS
int main()
{
    //Declaration pointeur

    //Un pointeur pointe sur une ref mémoire
    //Un pointeur lors de son initialisation doit avoir un référence null

    int *pn_pointeurEntier = NULL;

    //Pointeur pointe sur une référence nEntier
    int n_entier = 10;

    pn_pointeurEntier = &n_entier;

    int n_entier2 = 11;

    *pn_pointeurEntier = 88;
    n_entier = 500;

    int **ppn_entier = &pn_pointeurEntier;

    n_entier = sommeEntiers(10, 88);

    printf("%d\n", n_entier);

    int n_resSomme = 0;

    somEntiers(56, 12, &n_resSomme);

    printf("%d\n", n_resSomme);

    char *pChar = NULL;
    char cChaine[TAILLE] = "Ludus";

    pChar = &cChaine;

    return 0;
}

int sommeEntiers(int n_a, int n_b)
{
    return n_a + n_b;
}

void somEntiers(int n_a, int n_b, int *pnRes)
{
    *pnRes = n_a + n_b;
}

