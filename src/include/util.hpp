#ifndef UTIL_H
#define UTIL_H

#include "SDL2/SDL.h"

class util
{
    public:
        static float distance(int x1, int y1, int x2, int y2);
        static float TriangleArea(SDL_Point a, SDL_Point b, SDL_Point c);
        static int roundUpToMultipleOfEight(int v);
};



#endif