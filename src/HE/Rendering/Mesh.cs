using System.Text;

namespace HE
{
    public sealed class Mesh
    {
        public List<Vertice> vertices = new List<Vertice>();
        public List<Polygon> polygons = new List<Polygon>();
        public Mesh(string file)
        {
            using (StreamReader sr = new StreamReader(file))
            {
                while (!sr.EndOfStream)
                {
                    StringBuilder line = new StringBuilder(sr.ReadLine() ?? "");
                    switch ($"{line[0]}{line[1]}")
                    {
                        case "v ":
                            string[] parsev = line.Replace("v ", "").ToString().Split(" ");
                            vertices.Add(new Vertice(float.Parse(parsev[0]), float.Parse(parsev[1]), float.Parse(parsev[2])));
                            break;
                        case "f ":
                            polygons.Add(new Polygon(line.Replace("f ", "").ToString()));
                            break;
                    }
                }
                sr.Close();
            }
        }
    }
}