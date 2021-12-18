using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Threading;
using OpenTK;
using OpenTK.Windowing.Desktop;
using OpenTK.Mathematics;
using OpenTK.Windowing.Common;
using OpenTK.Graphics.OpenGL;

namespace HeadshotEngine
{
    public class EngineStart
    {
        public static List<GameObject> AllObjects = new List<GameObject>();
        public Vector CameraPosition = Vector.Zero();
        internal GameWindow window;
        public EngineStart(Vector size, string title)
        {
            window = new GameWindow(GameWindowSettings.Default, NativeWindowSettings.Default);
            window.Title = title;
            window.Size = new Vector2i((int)size.x, (int)size.y);
            window.Load += Load;
            window.Resize += Resize;
            window.RenderFrame += Render;
            window.Run();
            window.Dispose();
        }
        private void Load() => window.VSync = VSyncMode.On;
        private void Resize(ResizeEventArgs args) => GL.Viewport(0, 0, window.ClientSize.X, window.ClientSize.Y);
        private void Render(FrameEventArgs args)
        {
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            GL.MatrixMode(MatrixMode.Projection);
            GL.LoadIdentity();
            GL.Ortho(-1.0, 1.0, -1.0, 1.0, 0.0, 4.0);
            foreach (GameObject obj in AllObjects)
            {
                obj.Render();
            }
        }
        public virtual void OnLoad()
        {

        }
        public virtual void OnUpdate()
        {

        }
        public virtual void OnDraw()
        {
            
        }
        public virtual void OnClose()
        {
            
        }
        public virtual void KeyPressed(KeyboardKeyEventArgs args)
        {
            
        }
        public virtual void KeyUnpressed(KeyboardKeyEventArgs args)
        {
            
        }
        public virtual void MouseClick(MouseButtonEventArgs args)
        {
            
        }
        internal static void Register(GameObject obj)
        {
            AllObjects.Add(obj);
        }
        internal static void UnRegister(GameObject obj)
        {
            AllObjects.Remove(obj);
        }
    }
}