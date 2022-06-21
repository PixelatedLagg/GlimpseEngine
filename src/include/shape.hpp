class basicShape
{
    public:
        void SetPosX(int x);
        void SetPosY(int y);
        void SetSizeX(int x);
        void SetSizeY(int y);
        virtual void Render();
};

enum shape
{
    Rectangle,
    Triangle,
    Circle
};