#define SDL_MAIN_HANDLED

#include <iostream>
#include "include/game.hpp"
#include "include/event.hpp"
#include "include/line.hpp"

int offset = 1;
class hooks : public Event
{
    private:
        circle c;
        line b1;
        line b2;
        line b3;
        float vel;

    public:
        hooks() :
        c({400, 400}, 30),
        b1(100, 100, 100, 500), 
        b2(100, 500, 500, 500),
        b3(500, 500, 500, 100) {} //intialize stuff

        void Start() override
        {
            vel = 0;
            Game::AddObj(&c);
            Game::AddObj(&b1);
            Game::AddObj(&b2);
            Game::AddObj(&b3);
        }
        void Update() override
        {
            return;
        }
        void FixedUpdate() override
        {
            vel += 1;
            c.UpdateCenter({c._center.x, (int)(c._center.y + vel)});
            std::cout << c._radius << "<-RAD" << std::endl;
            std::cout << c.l_radius << "<-LRAD" << std::endl;
            Game::CheckAllCollisions();
            /*if (c.Colliding(&c2))
            {
                offset = -1;
            }*/
        }
};

int main()
{
    Game::event = new hooks();
    Game::Start();
    return 0;
}