#define SDL_MAIN_HANDLED

#include <iostream>
#include "include/gobj.hpp"
#include "include/app.hpp"
#include "include/color.hpp"

gobj a("test");

class example : public application
{
   public:
      void OnStart()
      {
         rect* z = (new rect(200, 200, 100, 100))->SetColor(255, 255, 0, 255);
         a.con_visual = z;
         AddGobj(a);
      }
      void OnUpdate()
      {

      }
      void OnFixedUpdate()
      {
         std::cout << "aids\n";
         a.IncPosX(10);
      }
};
int main()
{
   example e;
   e.BGColor = rgba(255, 0, 255, 255);
   e.FixedUpdateInterval = 1000;
   e.Start("Testing Glimpse Engine");
   return 0;
}