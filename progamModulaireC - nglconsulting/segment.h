#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED
#pragma once
#include "point.h"
#define TSEG 10



typedef struct segment{

    point tabPoint[TSEG];


}segment;


extern point *getPointSegment(segment *mSeg);
extern void setPointSegment(segment *mSeg, const point Point[]);

#endif // SEGMENT_H_INCLUDED
