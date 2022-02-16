using System.Threading;
using System;
using System.Collections.Generic;

namespace HE
{
    public class Game
    {
        internal List<GObject> objects = new List<GObject>();
        public Action? OnUpdate = null;
        public Action? OnDraw = null;
        private Thread thread;
        private CancellationToken token;
        public Game()
        {
            thread = new Thread(Loop);
            thread.Start();
        }
        private void Loop()
        {
            OnUpdate?.Invoke();
            while (thread.IsAlive)
            {
                OnDraw?.Invoke();
            }
        }
        public void Stop()
        {
            Environment.Exit(0);
        }
        public void Initialize()
        {
            
        }
    }
}