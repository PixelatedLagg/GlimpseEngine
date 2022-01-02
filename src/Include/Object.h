#ifndef OBJ_H
#define OBJ_H

#include "BaseObject.h"

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
        Object(Types type, BaseObject obj);
    };
}

#endif