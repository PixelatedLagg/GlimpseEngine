using System.Net.Http.Headers;
using System;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Markup.Xaml;
using Avalonia.Media;

namespace Editor
{
    public partial class MainWindow : Window
    {
        public MainWindow() => AvaloniaXamlLoader.Load(this);
        void TestClick(object sender, RoutedEventArgs args)
        {
            var b = (Button)sender;
            if (b.Content.ToString() == "aids")
            {
                b.Content = "not aids";
            }
            else
            {
                b.Content = "aids";
            }
        }
        //menu controls
        void Exit(object sender, RoutedEventArgs args)
        {
            Environment.Exit(0);
        }
        void OpenProject(object sender, RoutedEventArgs args)
        {
            OpenFileDialog file = new OpenFileDialog();
            file.Title = "Open Project";
            file.ShowAsync(this);
        }
        void NewProject(object sender, RoutedEventArgs args)
        {
            Environment.Exit(0);
        }
        void NewObject(object sender, RoutedEventArgs args)
        {
            Environment.Exit(0);
        }
        void RemoveObject(object sender, RoutedEventArgs args)
        {
            Environment.Exit(0);
        }
    }
}
