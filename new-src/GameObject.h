#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "V3.h"
#include "Collider.h"

#include <stdbool.h>

typedef struct GameObject GameObject;

struct GameObject
{
    char *name;
    V3 *position, *scale, *rotation;
    Collider *collider;
};

GameObject *NewGObject(char *name, V3 *position, V3 *scale, V3 *rotation);

bool *IsColliding(GameObject *obj1, GameObject *obj2);

#endif
