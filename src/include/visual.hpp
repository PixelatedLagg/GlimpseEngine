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
        void StartRender(SDL_Renderer* renderer);
        virtual void InitRender(SDL_Renderer* renderer);
        virtual void Render(SDL_Renderer* renderer);
};
class rect : public visual
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
        rect* SetColor(int r, int g, int b, int a);
        void InitRender(SDL_Renderer* renderer) override { }
        void Render(SDL_Renderer* renderer) override;
    private:
        SDL_Rect sdl;
        rgba color;
};

#endif