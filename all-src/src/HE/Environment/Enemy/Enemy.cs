namespace HE
{
    public interface Enemy
    {
        void Attack(params object[] args);
        void Die(params object[] args);
        void Spawn(params object[] args);
        void Special(params object[] args);
    }
}