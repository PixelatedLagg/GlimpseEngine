using System.Collections.Generic;

namespace HE
{
    public struct Polygon
    {
        public readonly Vertice[] vertices;
        public Polygon(Vertice[] vertices)
        {
            this.vertices = vertices;
        }
        public Polygon(string input)
        {
            List<Vertice> vertices = new List<Vertice>();
            foreach (string s in input.Split(" "))
            {
                vertices.Add(new Vertice(s));
            }
            this.vertices = vertices.ToArray();
        }
    }
}