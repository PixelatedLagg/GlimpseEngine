#ifndef COLLIDER_H
#define COLLIDER_H

#include "V3.h"
#include "V2.h"
#include "GameObject.h"

typedef struct Collider Collider;

struct Collider
{
    //0 BTL, 1 BTR, 2 BBL, 3 BBR, 4 TTL, 5 TTR, 6 TBL, 7 TBR
    V3 *vertices[8];
    V2 *xbound, *ybound, *zbound;
};

Collider *NewColl(GameObject *obj);

#endif