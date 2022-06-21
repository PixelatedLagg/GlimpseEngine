#include <iostream>

#include "include/gobj.hpp"
#include "include/game.hpp"

using namespace std;

int main()
{
   game g;
   g.Start("aids!");
   g.Pause(30000);
   return 0;
}