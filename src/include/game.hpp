#ifndef GAME_H
#define GAME_H

#include <vector>
#include "gobj.hpp"

class game
{
    public:
        void Start(char* title);
        void Stop();
        void Pause(int ms);
        void AddGobj(gobj* gobj);
    private:
        void Loop();
        std::vector<gobj> _Objects;
        int _FPS;
};

#endif