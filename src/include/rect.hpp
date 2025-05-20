#ifndef RECT_H
#define RECT_H

#include "SDL2/SDL.h"
#include <vector>

class rect
{
    public:
        rect(SDL_Point topleft, int length, int height);
        rect(SDL_Point topleft, SDL_Point topright, SDL_Point bottomleft, SDL_Point bottomright); 
        SDL_Point _topleft;
        SDL_Point _topright;
        SDL_Point _bottomleft;
        SDL_Point _bottomright;
        SDL_Point _center;
        void Render();
        bool Colliding(rect* other);
        void UpdateCenter(SDL_Point c);
};

#endif
