using System;
using System.Collections.Generic;

namespace HE
{
    public sealed class Level
    {
        private Map map;
        private List<Enemy> enemies;
        public Level(string file, Enemy[] enemies)
        {
            map = new Map(file);
            this.enemies = enemies.ToList();
        }
    }
}