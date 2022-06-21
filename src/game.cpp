#include <iostream>

#include "include/game.hpp"
#include "include/SDL2/SDL.h"

void game::Start(char* title)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    if(!window)
    {
        std::cout << "Window could not be created!\nSDL Error: " << SDL_GetError() << std::endl;
    }
}
void game::Stop()
{
    SDL_Quit();
}
void game::Pause(int ms)
{
    SDL_Delay(ms);
}
void game::AddGobj(gobj* gobj)
{
    _Objects.push_back(*gobj);
}