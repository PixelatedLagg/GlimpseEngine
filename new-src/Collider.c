#include "Collider.h"
#include "V3.h"
#include "GameObject.h"

Collider *NewColl(GameObject *obj)
{
    Collider *col;
    float x = *obj->scale->x / 2 + *obj->position->x, y = *obj->scale->y / 2 + *obj->position->y, z = *obj->scale->z / 2 + *obj->position->z;
    col->vertices[0] = NewV3(x - *obj->scale->x, y - *obj->scale->y, z);
    col->vertices[1] = NewV3(x, y - *obj->scale->y, z);
    col->vertices[2] = NewV3(x - *obj->scale->x, y - *obj->scale->y, z - *obj->scale->y);
    col->vertices[3] = NewV3(x, y - *obj->scale->y, z - *obj->scale->z);
    col->vertices[4] = NewV3(x - *obj->scale->x, y, z);
    col->vertices[5] = NewV3(x, y, z);
    col->vertices[6] = NewV3(x - *obj->scale->x, y, z - *obj->scale->z);
    col->vertices[7] = NewV3(x, y, z - *obj->scale->z);
    col->xbound = NewV2(col->vertices[4]->x, col->vertices[5]->x);
    col->xbound = NewV2(col->vertices[2]->y, col->vertices[6]->y);
    col->xbound = NewV2(col->vertices[3]->z, col->vertices[1]->z);
    return col;
} 