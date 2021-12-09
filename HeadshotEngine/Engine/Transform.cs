namespace HeadshotEngine
{
    internal enum TransformType
    {
        position,
        positionSize,
        positionRotation,
        positionSizeRotation
    }
    internal class Transform
    {
        internal (float x, float y) position;
        internal (float x, float y) size;
        internal float rotation;
        private int type;
        internal Transform(float x, float y)
        {
            position = (x, y);
            type = 0;
        }
        internal Transform(float x, float y, float sizex, float sizey)
        {
            position = (x, y);
            size = (sizex, sizey);
            type = 1;
        }
        internal Transform(float x, float y, float rotation)
        {
            position = (x, y);
            this.rotation = rotation;
            type = 2;
        }
        internal Transform(float x, float y, float sizex, float sizey, float rotation)
        {
            position = (x, y);
            size = (sizex, sizey);
            this.rotation = rotation;
            type = 3;
        }
        internal TransformType TransformType
        {
            get
            {
                switch (type)
                {
                    case 0:
                        return TransformType.position;
                    case 1:
                        return TransformType.positionSize;
                    case 2:
                        return TransformType.positionRotation;
                    case 3:
                        return TransformType.positionSizeRotation;
                }
            }
        }
    }
}