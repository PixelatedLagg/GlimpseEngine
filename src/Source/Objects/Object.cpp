#include <memory>
#include "Object.h"
#include "ComponentList.h"

namespace HeadshotEngine
{
    Object::Object(Types type)
    {
        switch (type)
        {
            case Position:
                //position Vector2(x, y)
                break;
            case Shape:
                //shape
                break;
            case Image:
                //image
                break;
            case Text:
                //image
                break;
            case Audio:
                //audio
                break;
            case Misc:
                //misc object
                break;
        }
    }
    void* Object::Delete()
    {
        
    }
    void* Object::AddComponent(ComponentList::List component)
    {
        componentCount++;
    }
    void* Object::DeleteComponent(ComponentList::List component)
    {
        componentCount--;
    }
    int componentCount = 0;
    ComponentList::List components[0];
}