#ifndef SHAPE_H
#define SHAPE_H

#include "BaseObject.h"
#include "ComponentList.h"

namespace HeadshotEngine
{
    class Shape : BaseObject
    {
        public:
        enum Shapes 
        { 
            Rectangle,
            Square,
            Circle,
            Triangle,
            Line
        };
        Shape(Shapes type);
        void* Delete();
        void* AddComponent(ComponentList::List component);
        void* DeleteComponent(ComponentList::List component);
    };
}

#endif