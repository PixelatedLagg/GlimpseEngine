using System.Collections.Generic;

namespace HE
{
    public sealed class EnemyManager
    {
        public List<Enemy> enemies = new List<Enemy>();
        public EnemyManager(params Enemy[] enemies)
        {
            this.enemies = enemies.ToList();
        }
        public void AddEnemy(params Enemy[] enemies)
        {
            foreach (Enemy e in enemies)
            {
                this.enemies.Add(e);
            }
        }
        public void RemoveEnemy(params Enemy[] enemies)
        {
            foreach (Enemy e in enemies)
            {
                this.enemies.Remove(e);
            }
        }
    }
}