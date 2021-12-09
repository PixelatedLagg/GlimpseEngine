namespace HeadshotEngine
{
    public struct Sprite : BaseComponent
    {
        private Transform transform;
        internal string tag;
        public Sprite(float x, float y, float sizex, float sizey, float? rotation)
        {
            if (rotation == null)
            {
                transform = new Transform(x, y, sizex, sizey);
            }
            else
            {
                transform = new Transform(x, y, sizex, sizey, rotation);
            }
            tag = null;
        }
        public Sprite(string tag, float x, float y, float sizex, float sizey, float? rotation)
        {
            if (rotation == null)
            {
                transform = new Transform(x, y, sizex, sizey);
            }
            else
            {
                transform = new Transform(x, y, sizex, sizey, rotation);
            }
            this.tag = tag;
        }
    }
}