#include "Object.h"
#include "ComponentList.h"
#include "BaseObject.h"

namespace HeadshotEngine
{
    BaseObject obj;
    Object::Object(int *type, BaseObject *obj, Transform *transform)
    {
        switch (*type)
        {
            case 0: //vector2
                obj->Render();
                break;
            case 1: //shape
                obj->Render();
                break;
            case 2: //text
                obj->Render();
                break;
            case 3: //image
                obj->Render();
                break;
            case 4: //audio
                obj->Render();
                break;
            case 5: //misc object
                obj->Render();
                break;
        }
        Object::transform = *transform;
    }
    int componentCount = 0;
    ComponentList::List components[0];
}