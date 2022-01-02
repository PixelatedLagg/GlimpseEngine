#ifndef OBJ_H
#define OBJ_H

#include <memory>
#include "ComponentList.h"


namespace HeadshotEngine
{
    class Object
    {
        public:
        enum Types 
        { 
            Position,
            Shape,
            Image,
            Text,
            Audio,
            Misc
        };
        Object(Types type);
        void* Delete();
        void* AddComponent(ComponentList::List component);
        void* DeleteComponent(ComponentList::List component);
    };
}

#endif