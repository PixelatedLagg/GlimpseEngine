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
        gobj(std::string _tag);
        void SetPosX(float x);
        void SetPosY(float y);
        void SetSizeX(float x);
        void SetSizeY(float y);
        void SetTag(std::string _tag);
        float GetPosX();
        float GetPosY();
        float GetSizeX();
        float GetSizeY();
        std::string GetTag();
        void AddColl();
        void AddVisual(visual _visual);
        bool hidden;
        void Render(SDL_Renderer* renderer);
        bool operator ==(const gobj obj);
    private:
        std::string tag;
        float posX, posY;
        float sizeX, sizeY;
        visual con_visual;
};

#endif