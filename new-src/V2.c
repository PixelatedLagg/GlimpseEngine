#include "V2.h"

#include <stdlib.h>

V2 *NewV2(const float x, const float y)
{
    V2 *v2 = malloc(sizeof(V2));
    if (!v2)
    {
        return v2;
    }
    v2->x = x;
    v2->y = y;
    return v2;
}