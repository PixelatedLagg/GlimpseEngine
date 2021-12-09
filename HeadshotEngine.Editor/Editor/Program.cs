using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using System;

namespace Editor
{
    class Program
    {
        [STAThread]
        public static void Main(string[] args) => BuildAvaloniaApp().StartWithClassicDesktopLifetime(args);
        public static AppBuilder BuildAvaloniaApp() => AppBuilder.Configure<App>().UsePlatformDetect().LogToTrace();
    }
}
