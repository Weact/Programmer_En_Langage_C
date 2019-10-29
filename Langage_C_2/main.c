#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10
#define MOT "HELLO"

//Les entrées et les sorties conversationnelles

int main()
{
    //exerciceUn();
    //exerciceDeux();
    //exerciceTrois();
    exerciceQuatre();
}


void number1()
{
    //Affichage
    printf("%d\n",TAILLE);
    printf("%s\n",MOT);

    //Saisie
    int val;
    scanf("%d",&val);
    fflush(stdin); //vide le buffer de la saisie
    char car;
    scanf("%c", &car);
    fflush(stdin);
    char tabCar[TAILLE];
    scanf("%s",tabCar);

    fgets(tabCar,TAILLE,stdin);
    printf("%s", tabCar);
}

void number2()
{

    char car;

    printf("Entrez un caractère\n");
    car=getchar();
    while( (car>='a' && car<='z') || (car>='A' && car<='Z') )
    {
        printf("%c\n",car);
        fflush(stdin);
        car=getchar();
    }
}

void exerciceUn()
{
    /*Programme de l'exercice :
    int i, n, som;
    som = 0;
    for (i = 0; i < 4; i++)
    {
        printf("donnez un entier");
        scanf("%d", &n);
        som += n;
    }
    printf("Somme : %d\n", som);
    */

    //AVEC WHILE AU LIEU DU FOR :
    printf("\nPROGRAMME DE L'EXERCICE UN AVEC UN WHILE !\n");
    int i, n, som;
    i = 0;
    som = 0;
    while(i < 4)
    {
        printf("Donnez un entier\n");
        scanf("%d", &n);
        som += n;
        i++;
    }
    printf("Somme : %d\n", som);

    //AVEC DO WHILE AU LIEU DU FOR :
    printf("\nPROGRAMME DE L'EXERCICE UN AVEC UN DO WHILE !\n");
    int ii, nn, somm;
    ii = 0;
    somm = 0;
    do{
        printf("Donnez un entier\n");
        scanf("%d", &nn);
        somm += nn;
        ii++;
    }while(ii < 4);
    printf("Somme : %d\n", somm);
}

void exerciceDeux()
{

    const int MIN_NOTE 0
    const int MAX_NOTE 20

    int nbNote;
    float note, moy; //ajouter noteMem si 2eme version du programme
    nbNote = 0;
    moy = 0;

    do{
        printf("Veuillez saisir la note. Une note negative arrete le programme.\n");
        scanf("%f", &note);
        if(note >= 0)
        {
            moy = moy + note;
            nbNote++;
        }
        else
            break;
    }while(note>=0);
    moy = moy / nbNote;
    printf("La moyenne des notes est de: %f\n", moy);

    /* Choix du nombre de note par l'utilisateur
    printf("\nCombien de note voulez-vous saisir ?\n");
    scanf("%d", &nbNote);
    //printf("%d", nbNote); DEBUG
    noteMem = nbNote;
    //printf("%d", noteMem); DEBUG

    do{
        printf("Veuillez saisir la note\n");
        scanf("%f", &note);
        moy = moy + note;
        nbNote--;
    }while(nbNote>0);
    moy = moy / noteMem;
    printf("La moyenne des notes est de: %f\n", moy);
    */
}

void exerciceTrois()
{
    printf("EXERCICE 3\n");

    const int NB_LIGNE 10
    int i,j;

    for(i=0; i<NB_LIGNE; i++){
        for(j=0; j<=i-1; j++){
            printf("*");
        }
        printf("*\n");
    }
}

void exerciceQuatre()
{
    int nb,i,prem;
    printf("Saisissez un nombre entier positif\n");
    scanf("%i",&nb);
    while(nb<0){
        printf("Saisissez un nombre entier positif\n");
        scanf("%i",&nb);
    prem = 1;
    }
    for(i=2;i<nb;i++){
        if (nb%i == 0){
            prem=0;
            break;
        }
    }

    if(prem){
        printf("le nombre est premier\n");
    }else{
        printf("le nombre n'est pas premier\n");
    }
}

void exerciceCinq()
{
    int nU1, nU2, nU3;
    int nN, nI;

    do{
        printf("rang du terme demande(au moins 3)\n");
        scanf("%d", &nN);
    }while(nN<3);

    nU2=nU1-1;
    nI2;
    while(nI++<nN){
        nU3=nU1+nU2;
        nU1=nU2;
        nU2=nU3;
    }
    printf("La valeur du terme ");
}

void exerciceSix()
{
    const int NMAX = 10;
    int nI, nJ;
    printf("    I");
    for(nJ = 1; nJ <= NMAX; nJ++)
        printf("-------");

    printf("\n");

    for(nI=1;nI<=NMAX;nI++)
    {
        printf("%4d", nI);

    }
}

void tableauStatiquesCours()
{
    int nTabInteger[TAILLE];
    float fltTabFloat[TAILLE];
    double dblTabDouble[TAILLE];

    char cTabChar[TAILLE];

    int nI = 0;

    for(nI=0; nI<TAILLE; nI++){
        nTabInteger[nI] = 0;
        fltTabFloat[nI] = 0.0;
        dblTabDouble[nI] = 0.0;
        cTabCar[nI] = '\0'; //caractere de fin de ligne
    }
}

void carteIdentities()
{
}
