#ifndef CIRCLE_H
#define CIRCLE_H

#include "SDL2/SDL.h"
#include <vector>

class circle
{
    private:
        std::vector<SDL_Point> pixels;
    public:
        circle(SDL_Point center, int radius); 
        void Render();
        void ReCalc();
        int _radius;
        SDL_Point _center;
        bool Colliding(circle* other);
        void UpdateRadius(int r);
        void UpdateCenter(SDL_Point c);
        int lastTimestamp;
        int l_radius;
        SDL_Point l_center;
        void RevertLast();
};

#endif