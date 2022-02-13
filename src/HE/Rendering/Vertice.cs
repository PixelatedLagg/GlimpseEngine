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
        public Vertice(string input)
        {
            string[] parse = input.Split("/");
            this.x = float.Parse(parse[0]);
            this.y = float.Parse(parse[1]);
            this.z = float.Parse(parse[2]);
        }
        public static Vertice Zero()
        {
            return new Vertice(0, 0, 0);
        }
    }
}