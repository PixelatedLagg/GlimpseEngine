#ifndef LINE_H
#define LINE_H

#include "circle.hpp"


class line
{
    public:
        line(int x1, int y1, int x2, int y2); 
        void Render();
        bool Colliding(circle* other);
        int _x1;
        int _y1;
        int _x2;
        int _y2;
        int l_x1;
        int l_y1;
        int l_x2;
        int l_y2;
        int lastTimestamp;
        void ChangePoints(int x1, int y1, int x2, int y2);
};

#endif