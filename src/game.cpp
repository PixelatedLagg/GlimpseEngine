#include <string>
#include "include/SDL2/SDL.h"
#include <thread>
#include <chrono>

#include "include/game.hpp"
#include "include/event.hpp"
#include <iostream>
#include "include/line.hpp"

bool running;
SDL_Window* Game::Window = nullptr;
SDL_Renderer* Game::Renderer = nullptr;
std::string Game::Title = "My Game";
std::vector<circle*> Game::Circles;
std::vector<line*> Game::Lines;
int Game::FixedUpdateInterval = 16; // 16 ms ~ 60 FPS
Event* Game::event = new Event();
int Game::globalTimestamp = 0;

void Game::UpdateCall()
{
    while (running)
    {
        Game::event->Update();
    }
}

void Game::FixedUpdateCall()
{
    while (running)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(Game::FixedUpdateInterval));
        Game::event->FixedUpdate();
    }
}

void RenderGobj()
{
    SDL_SetRenderDrawColor(Game::Renderer, 1, 1, 1, 1);
    SDL_RenderClear(Game::Renderer);
    for (auto circle : Game::Circles)
    {
        circle->Render();
    }
    for (auto line : Game::Lines)
    {
        line->Render();
    }

    SDL_RenderPresent(Game::Renderer);
}

void Game::AddObj(circle* obj)
{
    Game::Circles.push_back(obj);
}
void Game::AddObj(line* obj)
{
    Game::Lines.push_back(obj);
}

void Game::Start()
{
    globalTimestamp = 0;
    SDL_Init(SDL_INIT_EVERYTHING);
    Game::Window = SDL_CreateWindow(const_cast<char*>(Title.c_str()), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    if (!Game::Window)
    {
        return;
    }
    Game::Renderer = nullptr;
    Game::Renderer = SDL_CreateRenderer(Game::Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(Game::Renderer, 1, 1, 1, 1);
    event->Start();
    std::thread fixedUpdate(Game::FixedUpdateCall);
    std::thread update(Game::UpdateCall);
    running = true;
    while(running)
    {
        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            if (_event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        RenderGobj();
    }
    update.join();
    fixedUpdate.join();
    SDL_DestroyWindow(Game::Window);
    SDL_Quit();
}

void Game::CheckAllCollisions()
{
    for (auto circle : Game::Circles)
    {
        for (auto circle2 : Game::Circles)
        {
            if (circle == circle2)
            {
                continue;
            }
            if (circle->Colliding(circle2))
            {
                std::cout << "circle coll to circle" << std::endl;
                if (circle->lastTimestamp > circle2->lastTimestamp)
                {
                    circle->RevertLast();
                }
                else
                {
                    circle2->RevertLast();
                }
            }
        }
    }
    for (auto line : Game::Lines)
    {
        for (auto circle : Game::Circles)
        {
            if (line->Colliding(circle))
            {
                std::cout << "line coll to circle" << std::endl;
                if (circle->lastTimestamp > line->lastTimestamp)
                {
                    std::cout << "CIRCLE REVERTED" << std::endl;
                    circle->RevertLast();
                }
                else
                {
                    std::cout << "LINE REVERTED" << std::endl;
                    line->_x1 = line->l_x1;
                    line->_y1 = line->l_y1;
                    line->_x2 = line->l_x2;
                    line->_y2 = line->l_y2;
                }
            }
        }
    }
}