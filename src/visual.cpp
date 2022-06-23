#include "include/visual.hpp"
#include <iostream>

using namespace std;

void visual::StartRender(SDL_Renderer* renderer)
{
    Render(renderer);
}
void visual::Render(SDL_Renderer* renderer) 
{

}
void visual::SetPosX(int x) 
{
    cout << "A\n";
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
    sdl.x = x;
}
void rect::SetPosY(int y) 
{
    sdl.y = y;
}
void rect::SetSizeX(int x) 
{
    sdl.w = x;
}
void rect::SetSizeY(int y)
{
    sdl.h = y;
}
int rect::GetPosX()
{
    return sdl.x;
}
int rect::GetPosY()
{
    return sdl.y;
}
int rect::GetSizeX()
{
    return sdl.w;
}
int rect::GetSizeY()
{
    return sdl.h;
}
rect* rect::SetColor(int r, int g, int b, int a)
{
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return this;
}
void rect::Render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &sdl);
    SDL_RenderPresent(renderer);
}