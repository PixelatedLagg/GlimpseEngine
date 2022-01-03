#ifndef COLL_H
#define COLL_H

#include "Object.h"

namespace HeadshotEngine
{
    class Collider
    {
        public:
        bool* Check(Object* obj1, Object* obj2);
    };
}

#endif