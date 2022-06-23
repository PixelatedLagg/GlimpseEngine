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
void gobj::SetPosX(int x)
{
    con_visual->SetPosX(x - posX + con_visual->GetPosX());
    posX = x;
}
void gobj::SetPosY(int y)
{
    con_visual->SetPosX(y - posY + con_visual->GetPosY());
    posY = y;
}
void gobj::SetSizeX(int x)
{
    con_visual->SetSizeX(x - sizeX + con_visual->GetSizeX());
    sizeX = x;
}
void gobj::SetSizeY(int y)
{
    con_visual->SetSizeY(y - sizeY + con_visual->GetSizeY());
    sizeY = y;
}
void gobj::IncPosX(int x)
{
    con_visual->SetPosX(x + con_visual->GetPosX());
    sizeX += x;
}
void gobj::IncPosY(int y)
{
    con_visual->SetPosY(y + con_visual->GetPosY());
    sizeX += y;
}
void gobj::IncSizeX(int x)
{
    con_visual->SetSizeY(x + con_visual->GetSizeX());
    sizeX += x;
}
void gobj::IncSizeY(int y)
{
    con_visual->SetSizeY(y + con_visual->GetSizeY());
    sizeY += y;
}
void gobj::SetTag(std::string _tag)
{
    tag = _tag;
}
int gobj::GetPosX()
{
    return posX;
}
int gobj::GetPosY()
{
    return posY;
}
int gobj::GetSizeX()
{
    return sizeX;
}
int gobj::GetSizeY()
{
    return sizeY;
}
std::string gobj::GetTag()
{
    return tag;
}
void gobj::Render(SDL_Renderer* renderer)
{
    con_visual->Render(renderer);
}
bool gobj::operator ==(const gobj obj)
{
    if (tag == obj.tag)
    {
        return true;
    }
    return false;
}