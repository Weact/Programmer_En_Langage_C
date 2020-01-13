#include "droite.h"


point *getPointDroite(droite *mDroite){

    return mDroite->tabPoint;

}



void setPointDroite(droite *mDroite, const point Point[]){

        int i;

        for(i=0;i<TDROITE;i++){

            mDroite->tabPoint[i]=Point[i];
        }


}
