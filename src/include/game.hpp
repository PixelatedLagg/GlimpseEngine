#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "event.hpp"
#include "circle.hpp"
#include "SDL2/SDL.h"
#include "line.hpp"
#include "rect.hpp"

class Game
{
    public:
        static Event* event;
        static std::string Title;
        static int FixedUpdateInterval;
        static std::vector<circle*> Circles;
        static std::vector<line*> Lines;
        static std::vector<rect*> Rects;
        static SDL_Renderer* Renderer;
        static SDL_Window* Window;
        static void Start();
        static void AddObj(circle* obj);
        static void AddObj(line* obj);
        static void AddObj(rect* obj);
        static void CheckAllCollisions();
        static int globalTimestamp;
    private:
        static void UpdateCall();
        static void FixedUpdateCall();
};

#endif