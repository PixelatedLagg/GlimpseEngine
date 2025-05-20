#define SDL_MAIN_HANDLED

#include <iostream>
#include "include/game.hpp"
#include "include/event.hpp"
#include "include/line.hpp"

int offset = 1;
class hooks : public Event
{
    private:
        circle c3;

    public:
        hooks() :
        c3({100, 200}, 75)
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