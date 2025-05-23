#ifndef TENS_H
#define TENS_H

#include "SDL2/SDL.h"
#include <vector>

#include "circle.hpp"
#include "rect.hpp"

class tension
{
    public:
        tension(SDL_Point anchor, circle* circle);
        tension(SDL_Point anchor, rect* rect);
        SDL_Point _anchor;
        SDL_Point _centeroffset;
        void Render();
        bool Colliding(rect* other);
        void UpdateCenter(SDL_Point c);
};

#endif
