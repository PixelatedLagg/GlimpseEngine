#include <string>
#include "include/SDL2/SDL.h"
#include <thread>
#include <chrono>

#include "include/game.hpp"
#include "include/event.hpp"
#include <iostream>
#include "include/line.hpp"
#include "include/rect.hpp"

bool running;
SDL_Window* Game::Window = nullptr;
SDL_Renderer* Game::Renderer = nullptr;
std::string Game::Title = "My Game";
std::vector<circle*> Game::Circles;
std::vector<line*> Game::Lines;
std::vector<rect*> Game::Rects;
int Game::FixedUpdateInterval = 2; // 16 ms ~ 60 FPS
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

int sizeDirection = 1;
bool waitingToSpawn = false;
bool increasingSize = false;
int sizeDelay = 0;
circle* spawn = nullptr;
int startSpawnY = 0;


void RenderGobj()
{
    //SDL_SetRenderDrawColor(Game::Renderer, 1, 1, 1, 1);
    SDL_RenderClear(Game::Renderer);
    for (circle* circle : Game::Circles)
    {
        circle->Render();
    }
    for (line* line : Game::Lines)
    {
        line->Render();
    }
    for (rect* rect : Game::Rects)
    {
        rect->Render();
    }
    if ((SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1)) && waitingToSpawn)
    {
        spawn->Render();
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
void Game::AddObj(rect* obj)
{
    Game::Rects.push_back(obj);
}
void handleMouseDown(SDL_MouseButtonEvent e)
{
    if (e.button == SDL_BUTTON_LEFT)
    {
        if (e.clicks == 2) //double click spawns circle!
        {
            sizeDirection = 1;
            waitingToSpawn = true;
            spawn = new circle({e.x, e.y}, 1);
            sizeDelay = SDL_GetTicks();
        }
    }
    if (e.button == SDL_BUTTON_RIGHT)
    {
        if (waitingToSpawn)
        {
            startSpawnY = e.y;
            increasingSize = true;
        }
    }
}

void handleMouseUp(SDL_MouseButtonEvent e)
{
    if (e.button == SDL_BUTTON_LEFT && waitingToSpawn)
    {
        waitingToSpawn = false;
        increasingSize = false;
        Game::Circles.push_back(spawn);
    }
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
    while (running)
    {
        SDL_Event _event;
        Uint32 state = SDL_GetMouseState(NULL, NULL);
        if (state & SDL_BUTTON(3))
        {
            if (increasingSize && SDL_GetTicks() > sizeDelay)
            {
                int y;
                SDL_GetMouseState(NULL, &y);
                if (startSpawnY >= y)
                {
                    sizeDirection = 1;
                }
                else
                {
                    sizeDirection = -1;
                }
                sizeDelay += 500 / std::max(std::abs(y - startSpawnY), 1);
                spawn->UpdateRadius(spawn->_radius + sizeDirection);
            }
        }
        while (SDL_PollEvent(&_event))
        {
            if (_event.type == SDL_MOUSEBUTTONDOWN)
            {
                handleMouseDown(_event.button);
            }
            if (_event.type == SDL_MOUSEBUTTONUP)
            {
                handleMouseUp(_event.button);
            }
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
    for (circle* c : Game::Circles)
    {
        delete c;
    }
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