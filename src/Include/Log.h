#ifndef LOG_H
#define LOG_H

namespace HeadshotEngine
{
    class Log
    {
        public:
        static void* InfoLog(const char* msg);
        static void* WarningLog(const char* msg);
        static void* ErrorLog(const char* msg);
        enum LogTypes 
        { 
            Info, 
            Warning, 
            Error 
        };
    };
}

#endif