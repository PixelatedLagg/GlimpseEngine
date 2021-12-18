namespace HeadshotEngine.Internal
{
    internal class Project
    {
        internal string name;
        internal string password;
        internal List<Object> objects;
        internal Project(string name, string password, Object[] objects)
        {
            this.name = name;
            this.password = password;
            this.objects = objects.ToList();
        }
    }
}