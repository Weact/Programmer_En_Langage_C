#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 100

///TYPDEF
typedef struct tPoint{ //Signature du typedef

    int nX;
    int nY;

}tPoint; //Declaration du nouveau type

typedef struct coordonnee{ //Signature du typedef

    int nX;
    int nY;

}tJoueur, tEnnemi; //Declaration du nouveau type

typedef struct tDroite{ //Signature du typedef

    tPoint tabPoint[TAILLE];

}tDroite;

///DECLARATIONS DES METHODES
void setX(tPoint *pt, int nNewX);
void setY(tPoint *pt, int nNewY);
int getX(tPoint pt);
int getY(tPoint pt);
void createDroite(tDroite *dt, tPoint pt, int nIndex);
tPoint movePoint(tPoint *pt, int nMoveX, int nMoveY);

int main()
{
    tPoint newPoint;
    tPoint *pnewPoint=&newPoint;

    newPoint.nX = 5;
    newPoint.nY = 10;

    //FORMALISME POINTEUR NEW
    pnewPoint->nX=10;
    pnewPoint->nY=20;

    //FORMALISME POINTEUR OLD
    (*pnewPoint).nX = 50;
    (*pnewPoint).nY = 65;

    //Initialisation
    tPoint newPoint2 = {0,0}; //nX nY

    //Coordonnées Joueur
    tJoueur newJoueur = {0,0};
    tJoueur *pnewJoueur=&newJoueur;
    pnewJoueur->nX = 5;
    pnewJoueur->nY = 10;
    //Coordonnées Ennemi
    tEnnemi newEnnemi = {0,0};
    tEnnemi *pnewEnnemi=&newEnnemi;
    pnewEnnemi->nX = 10;
    pnewEnnemi->nY = 3;

    //Nouveau Point : Point3
    tPoint newPoint3 = {0,0};
    //Modification du X et Y du newPoint2 par l'intermédiaire des mutateurs
    setX(&newPoint3, 5);
    setY(&newPoint3, 17);

printf("\n");

    //Print les coordonnées de newPoint et newPoint2
    printf("%d et %d sont le X et le Y du Point(newPoint).\n", newPoint.nX, newPoint.nY);
    printf("%d et %d sont le X et le Y du Point(newPoint2).\n", newPoint2.nX, newPoint2.nY);

printf("\n");

    //Print les coordonnées du joueur et de l'ennemi
    printf("Les coordonnees du joueur sont [X]: %d [Y]: %d.\n", newJoueur.nX, newJoueur.nY);
    printf("Les coordonnees de l'ennemi sont [X]: %d [Y]: %d.\n", newEnnemi.nX, newEnnemi.nY);

printf("\n");

    //Print les nouvelles coordonnees du newPoint2
    printf("Les coordoonees du newPoint3 sont [X]: %d [Y]: %d.\n", getX(newPoint3), getY(newPoint3));

printf("\n");

    tDroite dt;
    int i;
    pnewPoint->nX = 0;
    pnewPoint->nY = 0;
    printf("Coordoonees du Point(newPoint) : [X]: %d [Y]: %d\n", getX(newPoint), getY(newPoint));
    for(i=0; i<TAILLE; i++)
    {
        createDroite(&dt,newPoint,i);
    }

printf("\n");

    tPoint movablePoint = {2,3};
    printf("Coordonnee du Point(movablePoint): [myPointX]: %d [myPointY]: %d\n", getX(movablePoint), getY(movablePoint));

    movePoint(&movablePoint, 5, 3);
    printf("Coordonnee du Point(movablePoint): [myPointX]: %d [myPointY]: %d\n", getX(movablePoint), getY(movablePoint));
    return 0;
}

///METHODES
void setX(tPoint *pt, int nNewX)
{
    pt->nX = nNewX;
}
void setY(tPoint *pt, int nNewY)
{
    pt->nX = nNewY;
}
int getX(tPoint pt)
{
    return pt.nX;
}
int getY(tPoint pt)
{
    return pt.nY;
}
tPoint movePoint(tPoint *pt, int nMoveX, int nMoveY)
{
    (*pt).nX+=nMoveX;
    (*pt).nY+=nMoveY;

    return *pt;
}

void createDroite(tDroite *dt, tPoint pt, int nIndex)
{
    dt->tabPoint[nIndex].nX = pt.nX + nIndex;
    dt->tabPoint[nIndex].nY = pt.nY + nIndex;
}
