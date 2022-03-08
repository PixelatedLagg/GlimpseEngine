#include "GameObject.h"
#include "V3.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GameObject *NewGObject(char *name, V3 *position, V3 *scale, V3 *rotation)
{
    GameObject *obj = malloc(sizeof(GameObject));
    if (!obj)
    {
        return obj;
    }
    obj->name = name;
    obj->position = position;
    obj->scale = scale;
    obj->rotation = rotation;
    obj->collider = NewColl(obj);
    return obj; 
}

Collider *NewColl(GameObject *obj)
{
    Collider *col;
    float x = obj->scale->x / 2 + obj->position->x, y = obj->scale->y / 2 + obj->position->y, z = obj->scale->z / 2 + obj->position->z;
    col->vertices[0] = *NewV3(x - obj->scale->x, y - obj->scale->y, z);
    col->vertices[1] = *NewV3(x, y - obj->scale->y, z);
    col->vertices[2] = *NewV3(x - obj->scale->x, y - obj->scale->y, z - obj->scale->y);
    col->vertices[3] = *NewV3(x, y - obj->scale->y, z - obj->scale->z);
    col->vertices[4] = *NewV3(x - obj->scale->x, y, z);
    col->vertices[5] = *NewV3(x, y, z);
    col->vertices[6] = *NewV3(x - obj->scale->x, y, z - obj->scale->z);
    col->vertices[7] = *NewV3(x, y, z - obj->scale->z);
    col->xbound = *NewV2(col->vertices[4].x, col->vertices[5].x);
    col->ybound = *NewV2(col->vertices[2].y, col->vertices[6].y);
    col->zbound = *NewV2(col->vertices[3].z, col->vertices[1].z);
    return col;
} 

bool *IsColliding(GameObject *obj1, GameObject *obj2)
{
    if ((obj1->collider->xbound.x <= obj2->collider->xbound.y && 
    obj1->collider->xbound.y >= obj2->collider->xbound.x) && 
    (obj1->collider->ybound.x <= obj2->collider->ybound.y && 
    obj1->collider->ybound.y >= obj2->collider->ybound.x) && 
    (obj1->collider->zbound.x <= obj2->collider->zbound.y && 
    obj1->collider->zbound.y >= obj2->collider->zbound.x))
    {
        return true;
    }
    return false;
}