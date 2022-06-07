#include "game.hpp"

void game::Start(int fps)
{
    _FPS = fps;
    Loop();
}
void game::AddGobj(gobj* gobj)
{
    _Objects.push_back(gobj);
}
void game::Loop()
{
    while (true)
    {
        
    }
}