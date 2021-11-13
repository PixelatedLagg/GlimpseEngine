using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Threading;

namespace HeadshotEngine
{
    public abstract class HeadshotEngine
    {
        private Vector ScreenSize = new Vector(0, 0);
        private string Title = null;
        private Thread GameLoopThread = null;
        public Color? BackgroundColor = null;
        public static List<GameObject> AllObjects = new List<GameObject>();
        public Vector CameraPosition = Vector.Zero();
        public float CameraAngle = 0f;
        public HeadshotEngine(Vector ScreenSize, string Title, Color Color)
        {
            Log.Info("[HeadshotEngine] HeadShot Engine 1.0.0");
            Log.Info("[HeadshotEngine] \u00a9 HeadShot Studios 2021");
            this.ScreenSize = ScreenSize;
            this.Title = Title;
            BackgroundColor = Color;
            GameLoopThread = new Thread(GameLoop);
            GameLoopThread.Start();
            Console.OutputEncoding = Encoding.UTF8;
            Console.Title = "Console";
        }
        void GameLoop()
        {
            OnLoad();
            while (GameLoopThread.IsAlive)
            {
                try
                {
                    OnDraw();
                    Renderer();
                    OnUpdate();
                    Thread.Sleep(1);
                }
                catch { }
            }
        }
        private void Renderer()
        {
            //call rendering
        }
        public abstract void OnLoad();
        public abstract void OnUpdate();
        public abstract void OnDraw();
        public abstract void OnClose();
        public abstract void KeyPressed(Key key);
        public abstract void KeyUnpressed(Key key);
        public abstract void MouseClick(Click click);
        internal static void Register(GameObject obj)
        {
            AllObjects.Add(obj);
        }
        internal static void UnRegister(GameObject obj)
        {
            AllObjects.Remove(obj);
        }
    }
    public class GameObject 
    {
        internal Type _type;
        public Type type
        {
            get
            {
                return _type;
            }
        }
    }
}