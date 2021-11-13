namespace HeadshotEngine
{
    public class Vector
    {
        public float x { get; set; }
        public float y { get; set; }
        public Vector()
        {
            x = 0;
            y = 0;
        }
        public Vector(float x, float y)
        {
            this.x = x;
            this.y = y;
        }
        public static Vector Zero() => new Vector(0, 0);
        public static Vector operator +(Vector a, Vector b) => new Vector(a.x + b.x, a.y + b.y);
        public static Vector operator +(Vector a, (float x, float y) b) => new Vector(a.x + b.x, a.y + b.y);
        public static Vector operator -(Vector a, Vector b) => new Vector(a.x - b.x, a.y - b.y);
        public static Vector operator -(Vector a, (float x, float y) b) => new Vector(a.x - b.x, a.y - b.y);
        public static Vector operator *(Vector a, Vector b) => new Vector(a.x * b.x, a.y * b.y);
        public static Vector operator *(Vector a, (float x, float y) b) => new Vector(a.x * b.x, a.y * b.y);
        public static Vector operator /(Vector a, Vector b) => new Vector(a.x / b.x, a.y / b.y);
        public static Vector operator /(Vector a, (float x, float y) b) => new Vector(a.x / b.x, a.y / b.y);
    }
}