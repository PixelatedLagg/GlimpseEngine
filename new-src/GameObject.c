#include "GameObject.h"
#include "V3.h"
#include "Collider.h"

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

bool *IsColliding(GameObject *obj1, GameObject *obj2)
{
    printf("haha\n");
    printf(obj1->collider->xbound->x);
    printf("haha\n");
    printf(obj1->collider->xbound->y);

    printf(obj1->collider->ybound->x);

    printf("haha\n");
    printf(obj1->collider->ybound->y);

    printf(obj1->collider->zbound->x);
    printf("haha\n");
    printf(obj1->collider->zbound->y);

    return (bool*)((obj1->collider->xbound->x <= obj2->collider->xbound->y && 
    obj1->collider->xbound->y >= obj2->collider->xbound->x) && 
    (obj1->collider->ybound->x <= obj2->collider->ybound->y && 
    obj1->collider->ybound->y >= obj2->collider->ybound->x) && 
    (obj1->collider->zbound->x <= obj2->collider->zbound->y && 
    obj1->collider->zbound->y >= obj2->collider->zbound->x));
}