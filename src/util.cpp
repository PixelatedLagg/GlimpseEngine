#include "include/util.hpp"
#include "math.h"

float util::distance(int x1, int y1, int x2, int y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) * 1.0);
}

float util::TriangleArea(SDL_Point a, SDL_Point b, SDL_Point c)
{
    float ABx = b.x - a.x;
    float ABy = b.y - a.y;
    float ACx = c.x - a.x;
    float ACy = c.y - a.y;
    float cross_product = ABx * ACy - ABy * ACx;
    return std::abs(cross_product) / 2.0f;
}

int util::roundUpToMultipleOfEight(int v)
{
    return (v + (8 - 1)) & -8;
}