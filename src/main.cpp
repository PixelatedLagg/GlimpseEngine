#define SDL_MAIN_HANDLED

#include <iostream>
#include "include/gobj.hpp"
#include "include/app.hpp"

using namespace std;

class example : public application
{
   public:
      void OnStart() override
      {
         gobj a("test");
         a.AddVisual(rect())
      }
      void OnUpdate() override
      {
         cout << "aids@EU(DJMND#)\n";
      }
};
int main()
{
   example e;
   e.Start("aids!");
   return 0;
}