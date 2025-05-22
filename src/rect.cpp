#include "include/rect.hpp"
#include "include/game.hpp"

rect::rect(SDL_Point topleft, int length, int height)
{
    _points[0] = topleft;
    _points[1] = {topleft.x + length, topleft.y};
    _points[2] = {topleft.x, topleft.y - height};
    _points[3] = {topleft.x + length, topleft.y - height};
}

rect::rect(SDL_Point topleft, SDL_Point topright, SDL_Point bottomleft, SDL_Point bottomright)
{
    _points[0] = topleft;
    _points[1] = topright;
    _points[2] = bottomleft;
    _points[3] = bottomright;
}

void rect::Render()
{
    SDL_RenderDrawLines(Game::Renderer, _points, 4);
}

bool rect::Colliding(rect* other)
{
    //if (other->_rect.x <= pointX && pointX < other->_rect.x + other->_rect.w &&)
    return false;
}