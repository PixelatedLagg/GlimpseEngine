using System.Collections.Generic;

namespace HE
{
    public sealed class GObject
    {
        internal List<Component> components = new List<Component>();
        internal Collider collider;
        public Transform Transform;
        public readonly string Id;
        public GObject(string id, Transform? transform = null)
        {
            if (transform == null)
            {
                Transform = new Transform(Vertice.Zero(), Vertice.Zero());
            }
            else
            {
                Transform = (Transform)transform;
            }
            Id = id;
        }
        public GObject AddCollider(bool trigger)
        {
            components.Add(new Collider(Transform, trigger));
            collider = new Collider(Transform, trigger);
            return this;
        }
        public bool IsColliding(GObject obj)
        {
            Collider c1 = collider, c2 = obj.collider;
            return (c1.xbound.x <= c2.xbound.y && c1.xbound.y >= c2.xbound.x) && (c1.ybound.x <= c2.ybound.y && c1.ybound.y >= c2.ybound.x) && (c1.zbound.x <= c2.zbound.y && c1.zbound.y >= c2.zbound.x);
        }
    }
}