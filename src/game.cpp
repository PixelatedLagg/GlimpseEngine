#include "game.hpp"
#include "include\SDL2-2.0.22\i686-w64-mingw32\include\SDL2\SDL.h"

void game::Start()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * screen = SDL_CreateWindow("My SDL Empty Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Delay(30000);
    SDL_Quit();
}
void game::AddGobj(gobj* gobj)
{
    _Objects.push_back(*gobj);
}