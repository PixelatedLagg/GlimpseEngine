#include "Shape.h"
#include "Vector.h"

namespace HeadshotEngine
{
    Vector2 area;
    Shape::Shape(Shapes type)
    {
        switch (type)
        {
            case Rectangle:
                //make rectangle
                break;
            case Square:
                //make square
                break;
            case Circle:
                //make circle
                break;
            case Triangle:
                //make triangle
                break;
            case Line:
                //make line
                break;
        }
    }
    void* Shape::Delete()
    {
        //dealloc space and delete
    }
    void* Shape::AddComponent(ComponentList::List component)
    {

    }
    void* Shape::DeleteComponent(ComponentList::List component)
    {
        
    }
}