#ifndef MATH_H
#define MATH_H

#include "SDL2/SDL.h"
#include <vector>

#include "rect.hpp"
#include "circle.hpp"
#include "line.hpp"

struct vec2
{
    float x;
    float y;
    vec2 add(vec2 other);
    vec2 subtract(vec2 other);
    vec2 divide(float num);
    vec2 multiply(float num);
    float dot(vec2 other);
};

#endif
