#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED
#pragma once
#include "point.h"
#define TCERCLE 10



typedef struct cercle{

    point tabPoint[TCERCLE];


}cercle;


extern point *getPointCercle(cercle *mCercle);
extern void setPointCercle(cercle *mCercle, const point Point[]);

#endif // CERCLE_H_INCLUDED
