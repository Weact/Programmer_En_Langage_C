#include <stdio.h>
#include <stdlib.h>

#define NFOIS 5

int main(int argc, char *argv[]) // 1
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

    return 0;
}
