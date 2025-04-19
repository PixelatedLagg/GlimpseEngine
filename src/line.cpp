#include "include/line.hpp"
#include "include/SDL2/SDL.h"
#include "include/game.hpp"
#include "include/util.hpp"
#include "include/circle.hpp"

line::line(int x1, int y1, int x2, int y2)
{
    lastTimestamp = 0;
    _x1 = x1;
    _y1 = y1;
    _x2 = x2;
    _y2 = y2;
}

void line::Render()
{
    SDL_SetRenderDrawColor(Game::Renderer, 100, 100, 100, 1);
    SDL_RenderDrawLine(Game::Renderer, _x1, _y1, _x2, _y2);
    SDL_SetRenderDrawColor(Game::Renderer, 1, 1, 1, 1);
}

bool line::Colliding(circle* other)
{
    return ((2 * util::TriangleArea(other->_center, {_x1, _y1}, {_x2, _y2})) / util::distance(_x1, _y1, _x2, _y2) <= other->_radius);
}

void line::ChangePoints(int x1, int y1, int x2, int y2)
{
    l_x1 = _x1;
    l_y1 = _y1;
    l_x2 = _x2;
    l_y2 = _y2;
    _x1 = x1;
    _y1 = y1;
    _x2 = x2;
    _y2 = y2;
    Game::globalTimestamp += 1;
    lastTimestamp = Game::globalTimestamp;
}