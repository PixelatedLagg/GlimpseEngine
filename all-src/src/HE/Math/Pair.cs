namespace HE
{
    public struct Pair
    {
        public float x;
        public float y;
        public Pair(float x, float y)
        {
            this.x = x;
            this.y = y;
        }  
        public static implicit operator string(Pair p)
        {
            return $"x: {p.x} y: {p.y}";
        }
        public override string ToString()
        {
            return $"x: {x} y: {y}";
        }
    }
}