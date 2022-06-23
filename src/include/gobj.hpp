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
        void SetPosX(int x);
        void SetPosY(int y);
        void SetSizeX(int x);
        void SetSizeY(int y);
        void IncPosX(int x);
        void IncPosY(int y);
        void IncSizeX(int x);
        void IncSizeY(int y);
        void SetTag(std::string _tag);
        int GetPosX();
        int GetPosY();
        int GetSizeX();
        int GetSizeY();
        std::string GetTag();
        void AddColl();
        bool hidden;
        void Render(SDL_Renderer* renderer);
        bool operator ==(const gobj obj);
        visual* con_visual;
    private:
        std::string tag;
        int posX, posY;
        int sizeX, sizeY;
};

#endif