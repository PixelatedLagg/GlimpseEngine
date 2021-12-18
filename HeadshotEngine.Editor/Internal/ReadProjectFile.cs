using System.IO;
using System.Collections.Generic;

namespace HeadshotEngine.Internal
{
    internal static class ReadProjectFile
    {
        internal static void Read(string file)
        {
            if (Path.GetExtension(file) != ".hsproj")
            {
                //error
                return;
            }
            try
            {
                List<Object> list = new List<Object>();
                string? name = null;
                string? password = null;
                foreach (string line in File.ReadLines(file))
                {
                    if (name == null)
                    {
                        name = line;
                        continue;
                    }
                    else if (password == null)
                    {
                        password = line;
                        continue;
                    }
                    var output = line.Split(' ');
                }   
                //Project project = new Project();
            }
            catch
            {

            }
        }
    }
}