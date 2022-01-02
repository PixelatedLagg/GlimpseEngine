#ifndef TRANS_H
#define TRANS_H

#include "Vector2.h"

namespace HeadshotEngine
{
    class Transform
    {
        public:
        Transform(Vector2* pos, Vector2* size, Vector2* rot = Vector2::Zero());
        void* Delete();
        Vector2* Position();
        Vector2* Size();
        Vector2* Rotation();
        void* Change(int* type, Vector2* arg);
    };
}

#endif