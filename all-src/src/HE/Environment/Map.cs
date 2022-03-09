using System;
using System.Collections.Generic;
using System.Text;

namespace HE
{
    public sealed class Map
    {
        Mesh mesh;
        EnemyManager enemyManager;
        public Map(string file, params Enemy[] enemies)
        {
            enemyManager = new EnemyManager(enemies);
            mesh = new Mesh(file);
        }
    }
}