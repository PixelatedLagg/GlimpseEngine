#include "include/visual.hpp"
#include <iostream>

using namespace std;

void visual::StartRender(SDL_Renderer* renderer)
{
    Render(renderer);
}
void visual::Render(SDL_Renderer* renderer) 
{
    std::cout << "aids!";
}
void visual::SetPosX(int x) 
{
    
}
void visual::SetPosY(int y) 
{
    
}
void visual::SetSizeX(int x) 
{
    
}
void visual::SetSizeY(int y)
{
    
}
int visual::GetPosX()
{
    return 0;
}
int visual::GetPosY()
{
    return 0;
}
int visual::GetSizeX()
{
    return 0;
}
int visual::GetSizeY()
{
    return 0;
}

rect::rect(int _posX, int _posY, int _sizeX, int _sizeY)
{
    sdl.x = _posX;
    sdl.y = _posY;
    sdl.w = _sizeX;
    sdl.h = _sizeY;
}
void rect::SetPosX(int x) 
{
    visual::SetPosX(x);
    sdl.x = x;
}
void rect::SetPosY(int y) 
{
    visual::SetPosY(y);
    sdl.y = y;
}
void rect::SetSizeX(int x) 
{
    visual::SetSizeX(x);
    sdl.w = x;
}
void rect::SetSizeY(int y)
{
    visual::SetSizeY(y);
    sdl.h = y;
}
int rect::GetPosX()
{
    return visual::GetPosX();
}
int rect::GetPosY()
{
    return visual::GetPosY();
}
int rect::GetSizeX()
{
    return visual::GetSizeX();
}
int rect::GetSizeY()
{
    return visual::GetSizeY();
}
rect rect::SetColor(int r, int g, int b, int a)
{
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return *this;
}
void rect::Render(SDL_Renderer* renderer)
{
    std::cout << "0!";
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    std::cout << "1!";
    SDL_RenderFillRect(renderer, &sdl);
    std::cout << "2!";
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    std::cout << "3!";
    SDL_RenderPresent(renderer);
    std::cout << "4!";
}