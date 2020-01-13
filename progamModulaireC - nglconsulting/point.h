#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#pragma once

#include <stdio.h>



typedef struct point{


    double x,y;



}point;



//Prototypes
extern void initPoint(point *mPoint,const double x, const double y);
extern void setPointX(point *mPoint, const double x);
extern void setPointY(point *mPoint, const double y);
extern double getPointX(const point mPoint);
extern double getPointY(const point mPoint);
extern void affichePoint(point mPoint);




#endif // POINT_H_INCLUDED
