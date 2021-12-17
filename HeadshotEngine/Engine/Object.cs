using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeadshotEngine
{
    public interface BaseComponent {}
    public enum Component
    {
        Collider
    }
    public enum ObjectType
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
        public Object(BaseComponent component)
        {
            switch (component.GetType().FullName)
            {
                case "HeadShotEngine.Sprite":
                    baseComponent = component;
                    break;
            }
            baseComponent = component;
            components = new List<Component>();
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
            switch (baseComponent.GetType().FullName)
            {
                case "HeadShotEngine.Sprite":
                    //render
                    break;
            }
        }
    }
}