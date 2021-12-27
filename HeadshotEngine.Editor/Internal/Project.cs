using System.Collections.Generic;
using System.Linq;
using HeadshotEngine;

namespace HeadshotEngine.Internal
{
    internal class Project
    {
        internal string name;
        internal string password;
        internal List<HeadshotEngine.GameObject> objects;
        internal Project(string name, string password, GameObject[] objects)
        {
            this.name = name;
            this.password = password;
            this.objects = objects.ToList();
            new HeadshotEngine
        }
    }
}