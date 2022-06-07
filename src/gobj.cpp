#include <string>

#include "include/gobj.hpp"
#include "include/coll.hpp"

gobj::gobj(std::string tag)
{
    Tag = tag;
    Components = {};
    std::cout << "[CREATION] gameobject with tag: " << tag << std::endl;
}
float gobj::GetPosX()
{
    return _X;
}
float gobj::GetPosY()
{
    return _Y;
}
float gobj::GetPosZ()
{
    return _Z;
}
void gobj::SetPos(float x, float y, float z)
{
    _X = x;
    _Y = y;
    _Z = z;
}
void gobj::AddColl()
{
    Components.push_back(coll(this));
}