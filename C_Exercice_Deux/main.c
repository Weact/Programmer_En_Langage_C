#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void initTable(int n_tabEntier[MAX]);
void readTable(int n_tabEntier[MAX]);

void *initTableP(int n_tabEntierPointeur[MAX]);
void *readTableP(int n_tabEntierPointeur[MAX]);

void initTableValues(int [], int);
void readTableValues(int [], int, int *, int *);

//void orderTabByAscendant(int [], int);

int main()
{
    srand(time(NULL)); //INIT TIME EVERY MAIN() EXECUTION

    printf("Hello world!\n");
    printf("Exercice 2\n");

//------------------------------------------------------------//

    //FORMATLISME TABLEAU
    printf("FORMATLISME TABLEAU\n");
    printf("-------------------------------------\n\n");

    int n_tabEntier[MAX];

    initTable(n_tabEntier);
    readTable(n_tabEntier);

    //FORMATLISME POINTEUR
    printf("\nFORMATLISME POINTEUR\n");
    printf("-------------------------------------\n\n");

    int n_tabEntierPointeur[MAX];

    initTableP(n_tabEntierPointeur);
    readTableP(n_tabEntierPointeur);

    //TABLEAU GET MIN MAX
    printf("\nTABLEAU DE RECUPERATION VALEUR MIN ET MAX DE TAILLE QUELCONQUES\n");
    printf("-------------------------------------\n\n");

    int dim = 5;
    int min = 0;
    int max = 0;
    printf("Dimension du tableau: %d\n\n", dim);
    int n_tabValues[dim];
    initTableValues(n_tabValues, dim);
    readTableValues(n_tabValues, dim, &min, &max);

    /*
    //TABLEAU TRIER ORDRE CROISSANT
    printf("\nTRIAGE D'UN TABLEAU DANS L'ORDRE CROISSANT\n");
    printf("-------------------------------------\n\n");
    */


}

//FORMATLISME TABLEAU
void initTable(int n_tabEntier[MAX])
{
    int i;
    printf("[NORMAL] Donnez %d valeurs\n", MAX);
    for(i = 0; i<MAX; i++)
    {
        scanf("%d", &n_tabEntier[i]);
        printf("[%d]\n\n", i+1);
    }
}

void readTable(int n_tabEntier[MAX])
{
    printf("---------------------------------------\n");
    printf("AFFICHAGE DU TABLEAU\n");
    int i;
    for(i = 0; i<MAX; i++)
    {
        if(i%5==0){printf("\n");}
        printf("[%d] ", n_tabEntier[i]);
    }
    printf("\n---------------------------------------\n");
}


//FORTMATLISME POINTEUR
//  *(nEntier+i)=0;//nEntier[i]=0
void * initTableP(int n_tabEntierPointeur[MAX])
{
    int i;
    printf("[POINTEUR] Donnez %d valeurs\n", MAX);

    for(i = 0; i<MAX; i++)
    {
        int n;
        scanf("%d", &n);
        *(n_tabEntierPointeur+i) = n;
        printf("[%d]\n\n", i+1);
    }
}

void * readTableP(int n_tabEntierPointeur[MAX])
{
    printf("---------------------------------------\n");
    printf("AFFICHAGE DU TABLEAU\n");
    int i;
    for(i = 0; i<MAX; i++)
    {
        if(i%5==0){printf("\n");}
        printf("[%d] ", n_tabEntierPointeur[i]);
    }
    printf("\n---------------------------------------\n");
}

//FORMATLISME TABLEAU
void initTableValues(int n_tabValues[], int dim)
{
    int i;
    printf("[MIN MAX] Donnez %d valeurs\n", dim);
    for(i = 0; i<dim; i++)
    {
        scanf("%d", &n_tabValues[i]);
        printf("[%d]\n\n", i+1);
    }
}

void readTableValues(int n_tabValues[], int dim, int *pMin, int *pMax)
{
    int i, min, max;
    min = n_tabValues[0];
    max = n_tabValues[0];

    printf("Lecture des valeurs et recherche du minimum/maximum...\n");
    for(i=0; i<dim; i++)
    {
        printf("Valeur [%d] : >%d< ", i, n_tabValues[i]);
        if(n_tabValues[i] < min){ min = n_tabValues[i]; };
        if(n_tabValues[i] > max){ max = n_tabValues[i]; };
        printf("[MIN = %d] ; [MAX = %d]\n", min, max);
    }
    *pMin = min;
    *pMax = max;

    printf("Valeur Min --> %d /// Valeur Max --> %d", min, max);
}

/*
void orderTabByAscendant(int n_tabToOrderBy[], int n)
{
    int i,f;
    for(i=0; i<n-1; i++)
    {
        if(n_tabToOrderBy[i] > n_tabToOrderBy[i+1])
        {
            f = n_tabToOrderBy[i];
            n_tabToOrderBy[i+1] = f;
            n_tabToOrderBy[]
        }
    }
}
*/

/*
Int nVal = 0 ;
Int *pInt = &&nVal ;

//nVal est associé dans la pile
*/
