namespace HE
{
    public struct Collider : Component
    {
        public readonly bool Trigger;
        private Vertice BTL, BTR, BBL, BBR, TTL, TTR, TBL, TBR;
        internal float initx, inity, initz;
        internal Collider(Transform transform, bool trigger)
        {
            Trigger = trigger;
            List<Vertice> vertices = new List<Vertice>();
            float x = (transform.Scale.x / 2) + transform.Position.x, y = (transform.Scale.y / 2) + transform.Position.y, z = (transform.Scale.z / 2) + transform.Position.z;
            BTL = new Vertice(x * -1, y * -1, z);
            BTR = new Vertice(x, y * -1, z);
            BBL = new Vertice(x * -1, y * -1, z * -1);
            BBR = new Vertice(x, y * -1, z * -1);
            TTL = new Vertice(x * -1, y, z);
            TTR = new Vertice(x, y, z);
            TBL = new Vertice(x * -1, y, z * -1);
            TBR = new Vertice(x, y, z * -1);
            initx = x;
            inity = y;
            initz = z;
        }
        public static bool IsColliding(GObject o1, GObject o2) //need to debug
        {
            Collider c1 = o1.collider, c2 = o2.collider;
            return (c1.initx * -1 <= c2.initx && c1.initx >= c2.initx * -1) && (c1.inity * -1 <= c2.inity && c1.inity >= c2.inity * -1) && (c1.initz * -1 <= c2.initz && c1.initz >= c2.initz * -1);
        }
    }
}