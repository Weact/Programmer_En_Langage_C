#include <stdio.h>
#include <stdlib.h>

#define NFOIS 5 //Constante
#define PI 3.14
#define Nom "DRUCKES"
#define CARAC 'E'


//Debut de l'apprentissage langage C - Ludus Academie - DRUCKES Lucas - 14 10 2019

int main(int argc, char *argv[]) // 1
{
    //CONSTANTE
    const int cnT = 10;
    const volatile cvnT = 13;
    const static csT = 15;

    //INTEGER
    short int nA; //short sN
    int nB;
    long int nC; //long lN

    //FLOAT
    float fltReelSimple;
    double dblReelDouble;

    //CHARACTER
    char cCharSimple;

    //OPERATEURS
    int nI = 0;
    ++nI; //pre-incrementation
    nI++; //post-incrementation
    //% : Modulo
    // '/' : Division
    //

    //CAST
    long double ldblLongDouble = 105.8933259635;
    printf("Valeur ldblLongDouble : %lf\n", (double)ldblLongDouble);

    //Operateurs relationnels
    // >
    // <
    // >=
    // <=
    // ==
    // !=

    //Operateurs Logiques
    // & ET
    // && ET
    // | OU
    // || OU
    // !

    printf("Taille de la constante : %d\n", sizeof(cnT));
    printf("Taille de la constante volatile : %d\n", sizeof(cvnT));
    printf("Taille de la constante static : %d\n", sizeof(csT));

    printf("Taille de a : %d\n", sizeof(nA));
    printf("Taille de b : %d\n", sizeof(nB));
    printf("Taille de c : %d\n", sizeof(nC));

    printf("Taille du float : %d\n", sizeof(fltReelSimple));
    printf("Taille du double : %d\n", sizeof(dblReelDouble));

    printf("Taille du char : %d\n", sizeof(cCharSimple));

    printf("Valeur de NFOIS : %d\n", NFOIS);
    printf("Valeur de PI : %f\n", PI);
    printf("Valeur de Nom : %s\n", Nom);
    printf("Valeur de CARAC : %c\n", CARAC);

    //EXEMPLE DE CONDITION

    //Sans opérateur logique :


    int nNombre = 2;
    if(nNombre != 2)
        printf("C'est different de 2 ! '%d'\n", nNombre);
    else
        printf("C'est egal a 2 ! '%d'\n", nNombre);


    //AVEC Opérateur logique :

    int nNombre1 = 15;
    int nNombre2 = 5;

    if((nNombre1 != 5) || (nNombre2 != 5))
        printf("Les deux variables ne sont pas egal a 5 ! '%d' et '%d'\n", nNombre1, nNombre2);
    else
        printf("Les deux variables sont egal a 5 ! '%d' et '%d'\n", nNombre1, nNombre2);

    //BOUCLE POUR
    for(int i = 0; i <= 10; i++)
    {
        if(i%2 == 0)
            printf("Le nombre %d est pair !\n", i);
        else
            printf("Le nombre %d est impair !\n", i);
    }

    //BOUCLE TANT QUE
    int g = 0;
    while(g <= 20)
    {
        if(g%5 == 0)
            printf("Le nombre %d est un multiple de 5 !\n", g);
        else
            printf("Le nombre %d n'est pas un multiple de 5 !\n", g);

        g++;
    }

    //BOUCLE FAIRE TANT QUE
    int h = 0;
    do{
        if(h%3 == 0)
            printf("Le nombre %d est un multiple de 3 !\n", h);
        else
            printf("Le nombre %d n'est pas un multiple de 3 !\n", h);

        h++;
    }while(h<=30);

    //CONDITION TERNAIRE
    int age = 18;
    int verif = (age >= 18) ? 1 : 0;

    if (verif == 1)
        printf("Il est majeur !");
    else if(verif == 0)
        printf("Il est mineur !");

}
/*
void main(int argc, char *argv[]) // 1
{
    int i;
    float x;
    float racx;

    printf("Bonjour\n");

    printf("Je vais vous calculer %d racines carree\n",NFOIS);

    for(i = 0; i < NFOIS; i++){
        printf("Donnez un nombre : ");
        scanf("%f", &x);
        if(x < 0.0)
            printf("Le nombre %f ne possède pas de racine carree\n", x);
        else{
            racx=sqrt(x);
            printf("Le nombre %f a pour racine carree : %f\n",x,racx);
        }

    }
    printf("Travail Termine - Au revoir");
}
*/
