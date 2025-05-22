#define SDL_MAIN_HANDLED

#include <iostream>
#include "include/game.hpp"
#include "include/event.hpp"
#include "include/line.hpp"

int offset = 1;
class hooks : public Event
{
    private:
        rect c3;

    public:
        hooks() :
        c3({0, 50}, {61, 300}, {30, 250}, {10, 420})
        {} //intialize stuff

        void Start() override
        {
            Game::AddObj(&c3);
        }
        void Update() override
        {
            return;
        }
        void FixedUpdate() override
        {
            return;
        }
};

int main()
{
    Game::event = new hooks();
    Game::Start();
    Game::FixedUpdateInterval = 2;
    return 0;
}