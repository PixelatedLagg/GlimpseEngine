namespace HeadshotEngine
{
    public class Sprite : GameObject
    {
        private Vector _position;
        public Vector position
        {
            get
            {
                return _position;
            }
        }
        private Vector _scale;
        public Vector scale
        {
            get
            {
                return _scale;
            }
        }
        private string _directory;
        public string directory
        {
            get
            {
                return _directory;
            }
        }
        private string _tag;
        public string tag
        {
            get
            {
                return _tag;
            }
        }
        public Sprite(Vector position, Vector scale, string directory, string tag)
        {
            _position = position;
            _scale = scale;
            _directory = directory;
            _tag = tag;
            _type = typeof(Sprite);
            HeadshotEngine.Register(this);
            Log.Info($"[Sprite]({tag}) - Has been registered!");
        }
        public void DestroySelf()
        {
            HeadshotEngine.Register(this);
            Log.Info($"[Sprite]({tag}) - Has been unregistered!");
        }
    }
}