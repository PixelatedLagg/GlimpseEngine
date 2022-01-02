#ifndef BOBJ_H
#define BOBJ_H

#include "ComponentList.h"

namespace HeadshotEngine
{
    class BaseObject
    {
        public:
        void* Render();
        void* Delete();
        void* AddComponent(ComponentList::List component);
        void* DeleteComponent(ComponentList::List component);
    };
}

#endif