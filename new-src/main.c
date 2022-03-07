#include "GameObject.h"
#include "V3.h"

#include <stdio.h>

int main()
{
    GameObject *o = NewGObject("e", NewV3(0.0F, 0.0F, 0.0F), NewV3(0.0F, 0.0F, 0.0F), NewV3(0.0F, 0.0F, 0.0F));
    GameObject *b = NewGObject("t", NewV3(0.0F, 0.0F, 0.0F), NewV3(0.0F, 0.0F, 0.0F), NewV3(0.0F, 0.0F, 0.0F));
    if (IsColliding(o, b))
    {
        printf("aids\n");
    }
    else
    {
        printf("hepatitis\n");
    }
    return 0;
}