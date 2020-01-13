
#include "point.h"


void initPoint(point *mPoint,const double x, const double y){

            mPoint->x=x;
            mPoint->y=y;

}


void setPointX(point *mPoint, const double x){


            mPoint->x=x;

}

void setPointY(point *mPoint, const double y){

        mPoint->y=y;

}

double getPointX(const point mPoint){

    return mPoint.x;

}

double getPointY(const point mPoint){

    return mPoint.y;

}


void affichePoint(point mPoint){

    printf("x : %.2lf, y : %.2lf",mPoint.x,mPoint.y);

}

