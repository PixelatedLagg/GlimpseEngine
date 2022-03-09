namespace HE
{
    public struct Collider : Component
    {
        public readonly bool Trigger;
        public Vertice[] vertices = new Vertice[8];
        //0 BTL, 1 BTR, 2 BBL, 3 BBR, 4 TTL, 5 TTR, 6 TBL, 7 TBR

        public Pair xbound, ybound, zbound;

        //0 lx, 1 ly, 2 lz, 3 hx, 4 hy, 5 hz
        internal Collider(Transform transform, bool trigger)
        {
            Trigger = trigger;
            float x = (transform.Scale.x / 2) + transform.Position.x, y = (transform.Scale.y / 2) + transform.Position.y, z = (transform.Scale.z / 2) + transform.Position.z;
            vertices[0] = new Vertice(x - transform.Scale.x, y - transform.Scale.y, z);
            vertices[1] = new Vertice(x, y - transform.Scale.y, z);
            vertices[2] = new Vertice(x - transform.Scale.x, y - transform.Scale.y, z - transform.Scale.z);
            vertices[3] = new Vertice(x, y - transform.Scale.y, z - transform.Scale.z);
            vertices[4] = new Vertice(x - transform.Scale.x, y, z);
            vertices[5] = new Vertice(x, y, z);
            vertices[6] = new Vertice(x - transform.Scale.x, y, z - transform.Scale.z);
            vertices[7] = new Vertice(x, y, z - transform.Scale.z);
            xbound = new Pair(vertices[4].x, vertices[5].x);
            ybound = new Pair(vertices[2].y, vertices[6].y);
            zbound = new Pair(vertices[3].z, vertices[1].z);
        }
    }
}