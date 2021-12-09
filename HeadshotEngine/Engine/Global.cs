using System.Runtime.InteropServices;

namespace HeadshotEngine.Internal
{
    internal enum OS
    {
        Windows,
        Linux,
        Mac
    }
    internal static class Global
    {
        internal static OS Platform;
        internal static void SetOS()
        {
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
            {
                Platform = OS.Windows;
            }
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
            {
                Platform = OS.Linux;
            }
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.OSX))
            {
                Platform = OS.Mac;
            }
        }
    }
}