#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "V3.h"
#include "V2.h"

#include <stdbool.h>

typedef struct
{
    //0 BTL, 1 BTR, 2 BBL, 3 BBR, 4 TTL, 5 TTR, 6 TBL, 7 TBR
    V3 vertices[8];
    V2 xbound, ybound, zbound;
} Collider;

typedef struct
{
    char *name;
    V3 position, scale, rotation;
    Collider collider;
} GameObject;

GameObject NewGObject(char name[], V3 position, V3 scale, V3 rotation);

Collider NewColl(GameObject obj);

bool IsColliding(GameObject obj1, GameObject obj2);

#endif
