#include "segment.h"


point *getPointSegment(segment *mSeg){

    return mSeg->tabPoint;

}



void setPointSegment(segment *mSeg, const point Point[]){

        int i;

        for(i=0;i<TSEG;i++){

            mSeg->tabPoint[i]=Point[i];
        }


}
