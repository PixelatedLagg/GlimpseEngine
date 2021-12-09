using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeadshotEngine
{
    internal interface BaseComponent {}
    internal enum Component
    {
        Collider
    }
    internal enum ObjectType
    {
        All,
        Sprite,
        Video,
        Audio,
        Canvas
    }
    public class Object
    {
        private BaseComponent baseComponent;
        private List<Component> components;
        public Object(ObjectType type)
        {
            switch (type)
            {
                case ObjectType.All:
                    break;
                case ObjectType.Sprite:
                    break;
                case ObjectType.Video:
                    break;
                case ObjectType.Audio:
                    break;
                case ObjectType.Canvas:
                    break;
            }
        }
        public Object(BaseComponent component)
        {
            switch (component.GetType())
            {
                case typeof(Sprite):
                    baseComponent = component;
                    break;
            }
        }
        public void AddComponent(Component component)
        {
            components.Add(component);
        }
        public void RemoveComponent(Component component)
        {
            components.Remove(component);
        }
        internal void Render()
        {
            foreach (Component component in components)
            {
                switch (component)
                {
                    case Component.Collider: //render collider
                        break;
                }
            }
            switch (baseComponent.GetType())
            {
                case typeof(Sprite): //render sprite
                    break;
            }
        }
        /*private Sprite sprite = null;
        public string tag = null;
        public enum Components { Physics = 0, Collider = 1 }
        private static bool[] hasComponents = new bool[2];

        //Physics Values
        public bool physicsActive = true;
        public float physicsGravity = 0;

        //Collider Values
        public bool colliderActive = true;
        public bool isTrigger = false;
        public Vector lastPos = new Vector(0, 0);
        private float? force = null;
        public event Action<Object2D> OnTriggerEnter;
        public event Action<Object2D> OnTriggerStay;
        public event Action<Object2D> OnTriggerExit;

        //Mouse Values
        public bool mouseActive = true;
        public event Action<Object2D> OnClick;
        public Object2D(Sprite sprite)
        {
            this.sprite = sprite;
            tag = $"{this.sprite.Tag}Obj";
            hasComponents[0] = false;
            hasComponents[1] = false;
            HeadshotEngine.Register(this);
            Log.Info($"[Object2D]({this.tag}) - Has been registered!");
        }
        public void DestroySelf()
        {
            HeadshotEngine.UnRegister(this);
            Log.Info($"[Object2D]({this.tag}) - Has been unregistered!");
        }
        public void AddComponent(Components components, object arg, object arg2 = null)
        {
            switch (components)
            {
                case Components.Physics:
                    if (hasComponents[0]) { Log.Error("Cannot add the same component twice!"); break; }
                    hasComponents[0] = true;
                    physicsGravity = (float)arg;
                    break;
                case Components.Collider:
                    if (hasComponents[1]) { Log.Error("Cannot add the same component twice!"); break; }
                    hasComponents[1] = true;
                    colliderActive = (bool)arg;
                    isTrigger = (bool)arg2;
                    lastPos.X = sprite.Position.X; //null error
                    lastPos.Y = sprite.Position.Y;
                    break;
            }
        }
        public void RemoveComponent(Components components)
        {
            switch (components)
            {
                case Components.Physics:
                    if (!hasComponents[0]) { Log.Error("Cannot remove a non-existent component!"); break; }
                    hasComponents[0] = false;
                    break;
                case Components.Collider:
                    if (!hasComponents[1]) { Log.Error("Cannot remove a non-existent component!"); break; }
                    hasComponents[1] = false;
                    break;
            }
        }
        public void ComponentCall()
        {
            if (hasComponents[0]) { PhysicsCall(); }
            if (hasComponents[1]) { ColliderCall(); }
        }
        private void PhysicsCall()
        {
            sprite.Position.Y += physicsGravity;
        }
        private void ColliderCall()
        {
            if (isTrigger)
            {
                foreach (Object2D obj in HeadshotEngine.AllObjects)
                {
                    if (obj.sprite.Position.X < sprite.Position.X + sprite.Scale.X &&
                        obj.sprite.Position.X + obj.sprite.Scale.X > sprite.Position.X &&
                        obj.sprite.Position.Y < sprite.Position.Y + sprite.Scale.Y &&
                        obj.sprite.Position.Y + obj.sprite.Scale.Y > sprite.Position.Y &&
                        obj != this)
                    {
                        OnTriggerStay?.Invoke(obj);
                    }
                }
                return;
            }
            if (IsColliding())
            {
                sprite.Position.X = lastPos.X;
                sprite.Position.Y = lastPos.Y;
            }
            else
            {
                lastPos.X = sprite.Position.X;
                lastPos.Y = sprite.Position.Y;
            }
        }
        public bool IsColliding()
        {
            foreach (Object2D obj in HeadshotEngine.AllObjects)
            {
                if (obj.sprite.Position.X < sprite.Position.X + sprite.Scale.X &&
                        obj.sprite.Position.X + obj.sprite.Scale.X > sprite.Position.X &&
                        obj.sprite.Position.Y < sprite.Position.Y + sprite.Scale.Y &&
                        obj.sprite.Position.Y + obj.sprite.Scale.Y > sprite.Position.Y &&
                        obj != this)
                {
                    return true;
                }
            }
            return false;
        }*/ //will work on this later
    }
}