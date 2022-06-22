#ifndef APP_H
#define APP_H

#include <vector>
#include "gobj.hpp"
#include "SDL2/SDL.h"
#include <set>

class application
{
    public:
        application();
        void Start(char* title);
        void Stop();
        void Pause(int ms);
        void FullScreenOn();
        rgba BGColor;
    protected:
        virtual void OnStart();
        virtual void OnUpdate();
        void AddGobj(gobj obj);
        void RemoveGobj(gobj obj);
        void RemoveAllGobj();
        int GobjCount();
    private:
        void RenderGobj();
        std::set<gobj> objects;
        bool running;
        SDL_Renderer* renderer;
        SDL_Window* window;
};

#endif