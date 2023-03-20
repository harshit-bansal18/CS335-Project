public class Singleton
{
    Singleton getInstance()
    {
        int x = 98;
        if (single_instance == null)
            single_instance = new Singleton();
  
        return single_instance;
    }
}