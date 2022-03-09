#include "GameObject.h"
#include "V3.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int b;
} Test;

Test TestInit()
{
    Test *t = malloc(sizeof(Test));
    if (!t)
    {
        return *t;
    }
    t->b = 0;
    t->i = 1;
    return *t;
}

int main()
{
    V3 v = NewV3(0.0F, 0.0F, 0.0F);
    GameObject o = NewGObject("e", NewV3(0.0F, 0.0F, 0.0F), NewV3(2.0F, 2.0F, 2.0F), NewV3(0.0F, 0.0F, 0.0F));
    GameObject b = NewGObject("t", NewV3(10000.0F, 0.0F, 0.0F), NewV3(1.0F, 1.0F, 1.0F), NewV3(0.0F, 0.0F, 0.0F));
    if (IsColliding(o, b))
    {
        printf("collided\n");
    }
    else
    {
        printf("did not collide\n");
    }
    return 0;
}