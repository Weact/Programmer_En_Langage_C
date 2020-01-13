#include "vue.h"

void afficheCercle(const cercle tCercle){

    int i=0;

    for(i=0;i<TCERCLE;i++){

            printf("%lf",tCercle.tabPoint[i].x);
            printf("%lf",tCercle.tabPoint[i].y);

    }

}
