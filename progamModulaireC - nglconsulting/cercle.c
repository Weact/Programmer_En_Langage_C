#include "cercle.h"

point *getPointCercle(cercle *mCercle){

    return mCercle->tabPoint;

}



void setPointCercle(cercle *mCercle, const point Point[]){

        int i;

        for(i=0;i<TCERCLE;i++){

            mCercle->tabPoint[i]=Point[i];
        }


}
