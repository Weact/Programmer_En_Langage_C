#include <stdio.h>
#include <stdlib.h>

#define LONGMAX 1000000000

int n = 5;

int main()
{
    printf("Hello world!\n\n");
    Exercice1();
    printf("\n");
    void fct (int p); //Ce programme affiche 5 et 3.
    int n = 3;
    fct(n);
    printf("\n");
    compterFonction();
    return 0;
}

void Exercice1()
{
    f1();
    f2(5);
    f3(2);
}

void f1()
{
    printf("Bonjour\n");
    printf("\n");
}

void f2(int i)
{
    int nI;
    for(nI = 0; nI<i; nI++)
    {
        printf("Bonjour f2 ! %d\n", nI+1);
    }
    printf("\n");
}

int f3(int j)
{
    int nJ;
    for(nJ = 0; nJ<j; nJ++)
    {
        printf("Bonjour f3 ! %d\n", nJ+1);
    }

    printf("\n");
    return 0;
}

void fct(int p)
{
    printf("%d %d\n\n", n, p);
}

void compterFonction()
{
    int i;
    for(i = 0; i<LONGMAX;i++)
    {
        compteAppel2();
    }
}

void compteAppel2()
{
    static int nAppel;
    nAppel++;
    if(nAppel == 1 || nAppel == 10 || nAppel == 100 || nAppel == 1000 || nAppel == 10000 ||  nAppel == 100000 ||  nAppel == 1000000 ||  nAppel == 10000000 ||  nAppel == 100000000 ||  nAppel == 1000000000)
        printf("Le nombre d'appel actuel est : %d.\n",nAppel);
}
