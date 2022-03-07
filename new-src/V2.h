#ifndef V2_H
#define V2_H

typedef struct V2 V2;

struct V2
{
    float *x;
    float *y;
};

V2 *NewV2(float *x, float *y);

#endif