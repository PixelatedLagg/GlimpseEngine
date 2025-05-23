#ifndef RB_H
#define RB_H

#include "SDL2/SDL.h"
#include <vector>

#include "rect.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "math.hpp"

class rigidbody
{
    public:
        rigidbody(SDL_Point center);
        float _mass = 1;
        float _kineticfriction = 0.3;
        float _staticfriction = 0.5;
        SDL_Point center;
        vec2 velocity;
        vec2 acceleration;
        vec2 netforce;
        vec2 nettorque;
        void AddForce(vec2 force);
        void Recalc();
};

#endif
