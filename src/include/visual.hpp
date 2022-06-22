#ifndef VISUAL_H
#define VISUAL_H

#include "SDL2/SDL.h"
#include "color.hpp"

class visual
{
    public:
        virtual void SetPosX(int x);
        virtual void SetPosY(int y);
        virtual void SetSizeX(int x);
        virtual void SetSizeY(int y);
        virtual int GetPosX();
        virtual int GetPosY();
        virtual int GetSizeX();
        virtual int GetSizeY();
        virtual void Render(SDL_Renderer* renderer);
};
class rect : private visual
{
    public:
        rect(int _posX, int _posY, int _sizeX, int _sizeY);
        void SetPosX(int x);
        void SetPosY(int y);
        void SetSizeX(int x);
        void SetSizeY(int y);
        int GetPosX();
        int GetPosY();
        int GetSizeX();
        int GetSizeY();
        void SetColor(int r, int g, int b, int a);
        void Render(SDL_Renderer* renderer);
    private:
        SDL_Rect* sdl;
        rgba* color;
};

#endif