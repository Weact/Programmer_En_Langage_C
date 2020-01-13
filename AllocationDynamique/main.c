#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("char : %d octets\n", sizeof(char));
    //printf("int : %d octets\n", sizeof(int));
    //printf("long : %d octets\n", sizeof(long));
    //printf("double : %d octets\n", sizeof(double));

    //int *pTabEntier = malloc(1000000000*sizeof(int));
    //int *pTabEntier = (int*)calloc(10,sizeof(int));

    //pTabEntier=(int*)realloc(pTabEntier,100);

    int *pTabEntier=(int*)calloc(1,sizeof(int));
    initTabEntier(pTabEntier);

    int i;
    for(i=0;i<10;i++)
    {
        pTabEntier[i] = 5;
    }

    free(pTabEntier);
}

void initTabEntier(int *pnEntier){
    pnEntier = (int*)calloc(10, sizeof(int));

}
