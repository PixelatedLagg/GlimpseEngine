#include "include/SDL2/SDL.h"
#include "include/shape.hpp"
#include "include/rect.hpp"

rect::Render()
{
    SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(m_window_renderer, &rect);
    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_window_renderer);
}