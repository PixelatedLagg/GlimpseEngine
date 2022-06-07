#include "coll.hpp"
#include "comptype.hpp"

#include <iostream>

coll::coll(gobj* parent)
{
    _Parent = parent;
}
comp_type coll::GetType()
{
    return COLL;
}
void coll::calc()
{
    std::cout << "[CALC] (x, y, z) " << _Parent->GetPosX() << "," << _Parent->GetPosY() << "," << _Parent->GetPosZ() << std::endl;
}
