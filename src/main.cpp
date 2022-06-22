#define SDL_MAIN_HANDLED

#include <iostream>
#include "include/gobj.hpp"
#include "include/app.hpp"
#include "include/color.hpp"

using namespace std;

class example : public application
{
   public:
      void OnStart()
      {
         gobj a("test");
         a.AddVisual(rect(0, 0, 100, 100).SetColor(255, 100, 0, 255));
         AddGobj(a);
      }
      void OnUpdate()
      {
         
      }
};
int main()
{
   example e;
   e.BGColor = rgba(255, 0, 255, 255);
   e.Start("Testing Glimpse Engine");
   return 0;
}