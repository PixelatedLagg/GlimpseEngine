#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "SDL2/SDL.h"
#include "visual.hpp"

class sprite : visual
{
    public:
        sprite(std::string _file, int _posX, int _posY, int _sizeX, int _sizeY);
        void SetPosX(int x);
        void SetPosY(int y);
        void SetSizeX(int x);
        void SetSizeY(int y);
        int GetPosX();
        int GetPosY();
        int GetSizeX();
        int GetSizeY();
        void InitRender(SDL_Renderer* renderer) override;
        void Render(SDL_Renderer* renderer) override;
    private:
        SDL_Texture *sdl;
        std::string file;
};

#endif