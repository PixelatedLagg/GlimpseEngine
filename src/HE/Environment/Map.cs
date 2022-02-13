using System;
using System.Collections.Generic;
using System.Text;

namespace HE
{
    public sealed class Map
    {
        Mesh mesh;
        public Map(string file)
        {
            mesh = new Mesh(file);
        }
    }
}