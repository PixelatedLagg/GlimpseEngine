#include "Object.h"
#include "ComponentList.h"
#include "BaseObject.h"

namespace HeadshotEngine
{
    BaseObject obj;
    Object::Object(Types type, BaseObject obj)
    {
        switch (type)
        {
            case Position:
                //position Vector2(x, y)
                break;
            case Shape:
                obj.Render();
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
    int componentCount = 0;
    ComponentList::List components[0];
}