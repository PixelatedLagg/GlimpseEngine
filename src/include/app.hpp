#ifndef APP_H
#define APP_H

#include <vector>
#include "gobj.hpp"
#include "SDL2/SDL.h"
#include <string>
#include <map>

class application
{
    public:
        application();
        void Start(std::string title);
        void Stop();
        void Pause(int ms);
        void FullScreenOn();
        rgba BGColor;
        int FixedUpdateInterval;
    protected:
        virtual void OnStart();
        virtual void OnUpdate();
        virtual void OnFixedUpdate();
        void AddGobj(gobj obj);
        gobj GetGobj(std::string tag);
        void RemoveGobj(std::string tag);
        void RemoveAllGobj();
        int GobjCount();
        void PauseUpdate(int ms);
    private:
        void RenderGobj();
        void UpdateCall();
        void FixedUpdateCall();
        std::map<std::string, gobj> objects;
        bool running;
        SDL_Renderer* renderer;
        SDL_Window* window;
};

#endif