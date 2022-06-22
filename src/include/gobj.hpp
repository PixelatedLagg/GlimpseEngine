#ifndef GOBJ_H
#define GOBJ_H

#include <string>
#include <iostream>
#include <vector>
#include "comp.hpp"
#include "visual.hpp"
#include "SDL2/SDL.h"

class gobj
{
    public:
        gobj(char* tag);
        void SetPosX(float x);
        void SetPosY(float y);
        void SetSizeX(float x);
        void SetSizeY(float y);
        void SetTag(char* _tag);
        float GetPosX();
        float GetPosY();
        float GetSizeX();
        float GetSizeY();
        char* GetTag();
        void AddColl();
        void AddVisual(visual _visual);
        bool hidden;
        void Render(SDL_Renderer* renderer);
    private:
        char* tag;
        float posX, posY;
        float sizeX, sizeY;
        visual* con_visual;
};

#endif