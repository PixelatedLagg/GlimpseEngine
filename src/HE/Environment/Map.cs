using System;
using System.Collections.Generic;
using System.Text;

namespace HE
{
    public sealed class Map
    {
        List<Vertice> vertices = new List<Vertice>();
        public Map(string file)
        {
            //need to find best way to parse the cryptic blend file
            byte[] contents = File.ReadAllBytes(file);
            Console.WriteLine(Convert.ToBase64String(contents));
            /*using (StreamReader sr = new StreamReader(file, Encoding.UTF8))
            {
                while (!sr.EndOfStream)
                {
                    Console.WriteLine(sr.);
                }
            }*/
        }
    }
}