#ifndef V3_H
#define V3_H

typedef struct
{
    float x;
    float y;
    float z;
} V3;

V3 NewV3(const float x, const float y, const float z);

#endif