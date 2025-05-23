#include "include/math.hpp"

vec2 vec2::add(vec2 other)
{
    return {other.x + x, other.y + y};
}

vec2 vec2::subtract(vec2 other)
{
    return {x - other.x, y - other.y};
}

float vec2::dot(vec2 other)
{
    return (other.x * x) + (other.y * y);
}

vec2 vec2::multiply(float num)
{
    return {x * num, y * num};
}

vec2 vec2::divide(float num)
{
    return {x / num, y / num};
}