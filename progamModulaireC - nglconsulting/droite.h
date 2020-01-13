#ifndef DROITE_H_INCLUDED
#define DROITE_H_INCLUDED
#pragma once
#include "point.h"
#define TDROITE 10




typedef struct droite{

    point tabPoint[TDROITE];


}droite;


extern point *getPointDroite(droite *mDroite);
extern void setPointDroite(droite *mDroite, const point Point[]);




#endif // DROITE_H_INCLUDED
