#include "include/rect.hpp"

rect::rect(SDL_Point topleft, int length, int height)
{
    _topleft = topleft;
    _topright = {_topleft.x + length, _topleft.y};
    _bottomleft = {_topleft.x, _topleft.y - height};
    _bottomright = {_topleft.x + length, _topleft.y - height};
}

rect::rect(SDL_Point topleft, SDL_Point topright, SDL_Point bottomleft, SDL_Point bottomright)
{
    _topleft = topleft;
    _topright = topright;
    _bottomleft = bottomleft;
    _bottomright = bottomright;
}

bool rect::Colliding(rect* other)
{
    //if (other->_rect.x <= pointX && pointX < other->_rect.x + other->_rect.w &&)
    return false;
}