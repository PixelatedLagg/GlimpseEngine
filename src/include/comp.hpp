#ifndef COMP_H
#define COMP_H

#include "comptype.hpp"

class comp
{
    public:
        comp();
        comp_type GetType();
    private:
        comp_type Type;
};

#endif