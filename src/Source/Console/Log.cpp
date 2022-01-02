#include <iostream>
#include "Log.h"

namespace HeadshotEngine
{
    void* Log::InfoLog(const char* msg)
    {
        cout << &msg << endl;
    }
    void* Log::WarningLog(const char* msg)
    {
        cout << &msg << endl;
    }
    void* Log::ErrorLog(const char* msg)
    {
        cout << &msg << endl;
    }
}