namespace HeadshotEngine
{
    public class Text
    {
        private Vector _position;
        public Vector position
        {
            get
            {
                return _position;
            }
        }
        private Vector _size;
        public Vector size
        {
            get
            {
                return _size;
            }
        }
        private string _text;
        public string text
        {
            get
            {
                return _text;
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
        public Text(Vector position, string text, string tag, Vector size)
        {
            _position = position;
            _text = text;
            _tag = tag;
            _size = size;
        }
        public void DestroySelf() {}
    }
}