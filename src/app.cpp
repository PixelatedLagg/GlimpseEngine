#include <string>
#include "include/app.hpp"
#include "include/SDL2/SDL.h"
#include <thread>
#include <chrono>

application::application()
{
    BGColor = rgba(255, 0, 255, 255);
    FixedUpdateInterval = 1000;
}
void application::FixedUpdateCall()
{
    while (running)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(FixedUpdateInterval));
        OnFixedUpdate();
    }
}
void application::Start(std::string title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(const_cast<char*>(title.c_str()), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
    if (!window)
    {
        return;
    }
    renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
    OnStart();
    std::thread thread{};
    running = true;
    while(running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        RenderGobj();
        OnUpdate();
    }
    thread.join();
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void application::OnStart() { }
void application::OnUpdate() { }
void application::OnFixedUpdate() { }
void application::Stop()
{
    running = false;
}
void application::Pause(int ms)
{
    SDL_Delay(ms);
}
void application::FullScreenOn()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}
void application::RenderGobj()
{
    SDL_SetRenderDrawColor(renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
    SDL_RenderClear(renderer);
    for (auto obj : objects)
    {
        obj.second.Render(renderer);
    }
    SDL_RenderPresent(renderer);
}
void application::AddGobj(gobj obj)
{
    objects.insert(std::pair(obj.GetTag(), obj));
}
gobj application::GetGobj(std::string tag)
{
    return objects.find(tag)->second;
}
void application::RemoveGobj(std::string tag)
{
    objects.erase(tag);
}
void application::RemoveAllGobj()
{
    objects.clear();
}
int application::GobjCount()
{
    return objects.size();
}