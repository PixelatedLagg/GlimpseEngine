#ifndef GOBJ_H
#define GOBJ_H

#include <string>
#include <iostream>
#include <vector>

#include "comp.hpp"

class gobj
{
    public:
        gobj(std::string tag);
        float GetPosX();
        float GetPosY();
        float GetPosZ();
        void SetPos(float x, float y, float z);
        void AddColl();
        void AddTexture();
        std::string Tag;
    private:
        float _X, _Y, _Z;
        std::vector<comp> Components;
};

#endif