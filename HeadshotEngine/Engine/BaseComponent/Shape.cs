namespace HeadshotEngine
{
    public struct Shape : BaseComponent
    {
        private Vector transform;
        internal string? tag;
        private ShapeType type;
        public Shape(Vector transform, float length, string? tag = null)
        {
            if (tag != null)
            {
                this.tag = tag;
            }
            else
            {
                this.tag = null;
            }
            this.transform = new Vector(transform.x, transform.y);
            type = ShapeType.Square;
        }
        public void Render()
        {
            //render
        }
    }
}