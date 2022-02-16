using System.Collections.Generic;

namespace HE
{
    public sealed class GObject
    {
        private List<Component> components = new List<Component>();
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
            return this;
        }
    }
}