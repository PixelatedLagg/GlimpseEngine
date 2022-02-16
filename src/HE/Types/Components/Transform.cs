namespace HE
{
    public struct Transform : Component
    {
        public float Rotation
        {
            get
            {
                return _rotation;
            }
        }
        private float _rotation;
        public Vertice Position
        {
            get
            {
                return _position;
            }
        }
        private Vertice _position;
        public Vertice Scale
        {
            get
            {
                return _scale;
            }
        }
        private Vertice _scale;
        public Transform(Vertice position, Vertice scale, float rotation = 0)
        {
            _position = position;
            _scale = scale;
            _rotation = rotation;
        }
        public static bool IsColliding(Transform t1, Transform t2)
        {
            return true;
            /*
            return (a.minX <= b.maxX && a.maxX >= b.minX) &&
            (a.minY <= b.maxY && a.maxY >= b.minY) &&
            (a.minZ <= b.maxZ && a.maxZ >= b.minZ);
            */
        }
    }
}