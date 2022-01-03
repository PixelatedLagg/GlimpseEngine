#include "Constants.h"

namespace HeadshotEngine
{
    static float _gravity = 3; //default value
    float* Constants::Gravity(float* gravity)
    {
        _gravity = *gravity;
        return gravity;
    }
}