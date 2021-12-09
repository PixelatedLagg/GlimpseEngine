using System;

namespace HeadshotEngine
{
    public static class Log
    {
        public static void Message(string msg)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine($"{DateTime.Now.ToString("hh:mm:ss")} [MSG] - {msg} ");
        }
        internal static void Warning(string msg)
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine($"{DateTime.Now.ToString("hh:mm:ss")} [WARNING] - {msg} ");
        }
        internal static void Error(string msg)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine($"{DateTime.Now.ToString("hh:mm:ss")} [ERROR] - {msg} ");
        }
    }
}