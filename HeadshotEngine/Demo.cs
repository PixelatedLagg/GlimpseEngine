using HeadshotEngine;
using OpenTK.Windowing.Common;

class Demo : EngineStart
{
    public Demo() : base(new Vector(300, 300), "aids") {}

    public override void KeyPressed(KeyboardKeyEventArgs args)
    {
        Console.WriteLine("aids");
    }

    public override void KeyUnpressed(KeyboardKeyEventArgs args)
    {
        throw new NotImplementedException();
    }

    public override void MouseClick(MouseButtonEventArgs args)
    {
        Console.WriteLine("aids");
    }

    public override void OnClose()
    {
        throw new NotImplementedException();
    }

    public override void OnDraw()
    {
        throw new NotImplementedException();
    }

    public override void OnLoad()
    {
        throw new NotImplementedException();
    }

    public override void OnUpdate()
    {
        throw new NotImplementedException();
    }
}