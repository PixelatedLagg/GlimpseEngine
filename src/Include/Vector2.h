#ifndef VEC2_H
#define VEC2_H

#include "BaseObject.h"
#include "ComponentList.h"

namespace HeadshotEngine
{
    class Vector2 : BaseObject
    {
        public:
        Vector2(float x, float y);
        void* Delete();
        float* GetPosition();
        static Vector2* Zero();
        float _x;
        float _y;
    };
}

#endif