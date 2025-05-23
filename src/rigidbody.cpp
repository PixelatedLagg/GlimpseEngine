#include "include/rigidbody.hpp"
#include "include/math.hpp"

#include "include/SDL2/SDL.h"

rigidbody::rigidbody(SDL_Point center)
{
    this->center = center;
}

void rigidbody::AddForce(vec2 force)
{
    netforce = netforce.add(force);
}

void rigidbody::Recalc()
{
    acceleration = netforce.divide(_mass);
    velocity = velocity.add(acceleration);
}