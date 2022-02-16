namespace HE
{
    public struct Collider : Component
    {
        public readonly bool Trigger;
        internal Vertice BTL, BTR, BBL, BBR, TTL, TTR, TBL, TBR;
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
        }
    }
}