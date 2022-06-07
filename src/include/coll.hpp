#ifndef COLL_H
#define COLL_H

#include "comp.hpp"
#include "gobj.hpp"

class coll : public comp
{
    public:
        coll(gobj* parent);
        comp_type GetType();
        void calc();
    private:
        gobj* _Parent;
};

#endif