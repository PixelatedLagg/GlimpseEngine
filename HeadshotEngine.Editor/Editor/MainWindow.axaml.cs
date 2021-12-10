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
        public MainWindow()
        {
            InitializeComponent();
        }
        private void InitializeComponent() => AvaloniaXamlLoader.Load(this);
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
        /*void PositionChange(object sender, RoutedEventArgs args)
        {
            TextBlock? text = this.FindControl<TextBlock>("aids") as TextBlock;
            if (text != null)
            {
                text.Text = "test";
            }
        }
        void Move(object sender, EventRoute args)
        {
            Panel? panel = sender as Panel;
            if (panel != null)
            {
                panel.Background = new SolidColorBrush(Color.FromArgb(100, 2, 3, 2));
            }
        }*/
    }
}
