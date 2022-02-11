using System.Threading;
using System;

namespace HE
{
    public class Game
    {
        private Thread thread;
        private CancellationToken token;
        public Game()
        {
            thread = new Thread(Loop);
            thread.Start();
        }
        private void Loop()
        {
            OnUpdate();
            while (thread.IsAlive)
            {
                OnDraw();
            }
        }
        private void OnUpdate()
        {

        }
        private void OnDraw()
        {

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