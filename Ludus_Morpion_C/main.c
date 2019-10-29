#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#DEFINE TAILLE 10

//PROTOTYPES
int n_randomNumber(int n_min, int n_max);

//MAIN
int main()
{
    printf("Hello world!\n");
    return 0;
}

//DECLARATION DES FONCTIONS
int n_randomNumber(int n_min, int n_max)
{
    int n_random = (rand() % (n_max - n_min + 1)) + n_min;

    return n_random;
}
