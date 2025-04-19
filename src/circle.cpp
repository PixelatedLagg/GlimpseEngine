#include "include/circle.hpp"
#include "include/SDL2/SDL.h"
#include <vector>
#include "include/game.hpp"
#include "math.h"
#include "include/util.hpp"

void circle::UpdateRadius(int r)
{
    if (r < 1)
    {
        l_radius = _radius;
        _radius = r;
        l_center = _center;
        return;
    }
    l_radius = _radius;
    _radius = r;
    l_center = _center;
    ReCalc();
    Game::globalTimestamp += 1;
    lastTimestamp = Game::globalTimestamp;
}

void circle::ReCalc()
{
    std::vector<SDL_Point> points;

    // 35 / 49 is a slightly biased approximation of 1/sqrt(2)
    const int arrSize = util::roundUpToMultipleOfEight(_radius * 8 * 35 / 49);
    points.reserve(arrSize);

    const int32_t diameter = (_radius * 2);

    int32_t x = (_radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while( x >= y )
    {
        // Each of the following renders an octant of the circle
        points.push_back( { _center.x + x, _center.y - y } );
        points.push_back( { _center.x + x, _center.y + y } );
        points.push_back( { _center.x - x, _center.y - y } );
        points.push_back( { _center.x - x, _center.y + y } );
        points.push_back( { _center.x + y, _center.y - x } );
        points.push_back( { _center.x + y, _center.y + x } );
        points.push_back( { _center.x - y, _center.y - x } );
        points.push_back( { _center.x - y, _center.y + x } );

        if( error <= 0 )
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if( error > 0 )
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }

    pixels = points; // RVO FTW
}

circle::circle(SDL_Point center, int radius)
{
    lastTimestamp = 0;
    _center = center;
    _radius = radius;
    ReCalc();
}

void circle::Render()
{
    SDL_SetRenderDrawColor(Game::Renderer, 100, 100, 100, 1);
    SDL_RenderDrawPoints(Game::Renderer, pixels.data(), pixels.size());
    SDL_SetRenderDrawColor(Game::Renderer, 1, 1, 1, 1);
}

bool circle::Colliding(circle* other)
{
    return (util::distance(other->_center.x, other->_center.y, _center.x, _center.y) < other->_radius + _radius);
}

void circle::UpdateCenter(SDL_Point c)
{
    l_center = _center;
    _center = c;
    l_radius = _radius;
    ReCalc();
    Game::globalTimestamp += 1;
    lastTimestamp = Game::globalTimestamp;
}

void circle::RevertLast()
{
    _center = l_center;
    _radius = l_radius;
    ReCalc();
}