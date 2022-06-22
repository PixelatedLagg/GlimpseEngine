#include <string>
#include "include/app.hpp"
#include "include/SDL2/SDL.h"

application::application()
{
    BGColor = rgba(255, 0, 255, 255);
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
    OnStart();
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
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void application::OnStart() { }
void application::OnUpdate() { }
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
        obj.Render(renderer);
    }
}
void application::AddGobj(gobj obj)
{
    objects.push_back(obj);
}
void application::RemoveGobj(gobj obj)
{
    objects.remove(obj);
}
void application::RemoveGobj(std::string tag)
{
    for (auto obj : objects)
    {
        if (obj.GetTag() == tag)
        {
            objects.remove(obj);
            return;
        }
    }
}
void application::RemoveAllGobj()
{
    objects.clear();
}
int application::GobjCount()
{
    return objects.size();
}