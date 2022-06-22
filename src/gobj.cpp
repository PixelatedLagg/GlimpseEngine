#include <string.h>
#include <iostream>
#include "include/gobj.hpp"
#include "include/coll.hpp"
#include "include/visual.hpp"

gobj::gobj(std::string _tag)
{
    tag = _tag;
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
void gobj::SetTag(std::string _tag)
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
std::string gobj::GetTag()
{
    return tag;
}
void gobj::AddVisual(visual _visual)
{
    con_visual = _visual;
}
void gobj::Render(SDL_Renderer* renderer)
{
    con_visual.Render(renderer);
}
bool gobj::operator ==(const gobj obj)
{
    if (tag == obj.tag)
    {
        return true;
    }
    return false;
}