
#include "define.h"
#include "vue.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{

    //Déclarations
    point tPoint;
    droite tDroite;
    droite *ptDroite2;
    segment tSeg;
    segment *ptSeg;
    cercle tCercle;
    cercle *ptCercle;
    int i;

    //Test Point
    point tabPoint[10];

    initPoint(&tPoint,10.2,8.8);

    affichePoint(tPoint);

    setPointX(&tPoint,8.8);
    setPointY(&tPoint,9.9);

    printf("\nx : %.2lf, y : %.2lf\n",getPointX(tPoint),getPointY(tPoint));


    //init tabPoint :


    for(i=0;i<10;i++){

        tabPoint[i].x=0.0;
        tabPoint[i].y=0.0;
    }

    //Test Droite,Segment,Cercle
    setPointDroite(&tDroite,tabPoint);
    ptDroite2=(droite*)getPointDroite(&tDroite);

    for(i=0; i<TDROITE;i++){
        printf("%lf",ptDroite2->tabPoint[i].x);
        printf("%lf",ptDroite2->tabPoint[i].y);
    }



    setPointSegment(&tSeg,tabPoint);
    ptSeg=(segment*)getPointSegment(&tSeg);

     for(i=0; i<TDROITE;i++){
        printf("%lf",ptSeg->tabPoint[i].x);
        printf("%lf",ptSeg->tabPoint[i].y);
    }

    setPointCercle(&tCercle,tabPoint);
    ptCercle=(cercle*)getPointCercle(&tCercle);

    for(i=0; i<TDROITE;i++){
        printf("%lf",ptCercle->tabPoint[i].x);
        printf("%lf",ptCercle->tabPoint[i].y);
    }

    //Test code vue
    printf("Test code vue\n");
    afficheCercle(tCercle);


    return 0;
}
