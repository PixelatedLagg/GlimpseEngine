#ifndef V3_H
#define V3_H

typedef struct V3 V3;

struct V3
{
    float *x;
    float *y;
    float *z;
};

V3 *NewV3(float x, float y, float z);

#endif