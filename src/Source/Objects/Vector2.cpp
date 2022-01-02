#include "Vector2.h"
#include <memory>

namespace HeadshotEngine
{
    float _x;
    float _y;
    Vector2::Vector2(float x, float y)
    {
        _x = x;
        _y = y;
    }
    void* Vector2::Delete()
    {
        //dealloc _x and _y and delete the vector
    }
    float* Vector2::GetPosition()
    {
        float position[2];
        position[1] = _x;
        position[2] = _y;
        return position;
    }
    Vector2* Vector2::Zero()
    {
        return new Vector2(0, 0);
    }
}