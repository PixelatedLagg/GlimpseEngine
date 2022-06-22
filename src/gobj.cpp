#include <string>
#include <iostream>
#include "include/gobj.hpp"
#include "include/coll.hpp"
#include "include/visual.hpp"

gobj::gobj(char* _tag)
{
    tag = _tag;
    con_visual = nullptr;
    std::cout << "[CREATION] gameobject with tag: " << tag << std::endl;
}
void gobj::SetPosX(float x)
{
    posX = x;
}
void gobj::SetPosY(float y)
{
    posY = y;
}
void gobj::SetSizeX(float x)
{
    sizeX = x;
}
void gobj::SetSizeY(float y)
{
    sizeY = y;
}
void gobj::SetTag(char* _tag)
{
    tag = _tag;
}
float gobj::GetPosX()
{
    return posX;
}
float gobj::GetPosY()
{
    return posY;
}
float gobj::GetSizeX()
{
    return sizeX;
}
float gobj::GetSizeY()
{
    return sizeY;
}
char* gobj::GetTag()
{
    return tag;
}
void gobj::AddVisual(visual _visual)
{
    con_visual = &_visual;
}
void gobj::Render(SDL_Renderer* renderer)
{
    if (con_visual != nullptr)
    {
        con_visual->Render(renderer);
    }
}