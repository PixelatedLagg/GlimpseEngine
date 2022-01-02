#include "Transform.h"
#include "Vector2.h"

namespace HeadshotEngine
{
    Vector2 _pos;
    Vector2 _size;
    Vector2 _rot;
    Transform::Transform(Vector2* pos, Vector2* size, Vector2* rot = Vector2::Zero())
    {
        _pos = *pos;
        _size = *size;
        _rot = *rot;
    }
    void* Transform::Delete()
    {   
        //dealloc _pos, _size, and _rot 
        //only meant to be called on when base object is deleted
    }
    void* Transform::Change(int* type, Vector2* arg)
    {
        switch (*type)
        {
            case 0:
                //call on renderer to change the position of object
                _pos = *arg;
                break;
            case 1:
                //call on renderer to change the size of object
                _size = *arg;
                break;
            case 2:
                //call on renderer to change the rotation of object
                _rot = *arg;
                break;
        }
    }
}