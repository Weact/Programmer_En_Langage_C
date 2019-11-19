#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 100
//Les pointeurs



char *ctabCar(char cChaine[100]);
int *ntabInt(int nEntier[100]);
int *ntabInt2D(int nEntier[10][10]);



int main()
{


    /*char cSaisie[100]={"Votre Nom"}; //Declaration Tableau de caractère;
    char *cNom;
    //Formalisme tableau
    cNom=ctabCar(cSaisie);
    printf("Votre Nom %s",cNom);*/




    //Tableau d'entiers
    int nEntier[100]={0};
    ntabInt(nEntier);

    int nEntier2[10][10];
    int *pInt=ntabInt2D(nEntier2);

    int i;
    int *p;
    for(i=0;i<100;i++){

        printf("%d",*(pInt)++);//Formalisme pointeur
        p=pInt;
    }

    //*(pInt)++; //incrémentation du pointeur et donc de la référence.

    //ou (*pInt)++ incrémentation de l'entier stocké


   return 0;
}


/* fonction retourne un pointeur de char*/

char * ctabCar(char cChaine[100]){

    printf("Entrez votre nom\n");
    scanf("%s",cChaine);

    return cChaine;

}

/* fonction retourne un pointeur de int*/
int * ntabInt(int nEntier[100])
{

    int i;

    //formatlisme pointeur
    for(i=0;i<100;i++){
        *(nEntier+i)=0;//nEntier[i]=0
    }

    return nEntier;
}


/* fonction retourne un pointeur de int, cast du tableau 2d en pointeur*/
int * ntabInt2D(int nEntier[10][10]){


    int i,j;

    //formatlisme pointeur
    for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                *(*(nEntier+i)+j)=10;//nEntier[i][j]=10;

            }

    }

    return (int*)nEntier;

}
