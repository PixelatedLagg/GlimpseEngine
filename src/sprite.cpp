#include "include/sprite.hpp"

sprite::sprite(std::string _file, int _posX, int _posY, int _sizeX, int _sizeY)
{
    file = _file;
}
void sprite::InitRender(SDL_Renderer* renderer)
{
    SDL_Surface *surface = SDL_LoadBMP(file.c_str());
    sdl = SDL_CreateTextureFromSurface(renderer, surface);
}
void sprite::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, sdl, NULL, NULL);
    SDL_RenderPresent(renderer);
}