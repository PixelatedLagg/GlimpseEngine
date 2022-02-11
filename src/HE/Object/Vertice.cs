namespace HE
{
    public struct Vertice
    {
        public float x;
        public float y;
        public float z;
        public Vertice(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        public static Vertice Zero()
        {
            return new Vertice(0, 0, 0);
        }
    }
}