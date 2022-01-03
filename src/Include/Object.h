#ifndef OBJ_H
#define OBJ_H

#include "BaseObject.h"
#include "Transform.h"

namespace HeadshotEngine
{
    class Object
    {
        public:
        Transform transform;
        Object(int *type, BaseObject *obj, Transform *transform);
    };
}

#endif