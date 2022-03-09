#include "V3.h"

#include <stdlib.h>

V3 NewV3(const float x, const float y, const float z)
{
    V3 *v3 = malloc(sizeof(V3));
    if (!v3)
    {
        return *v3;
    }
    v3->x = x;
    v3->y = y;
    v3->z = z;
    return *v3;
}