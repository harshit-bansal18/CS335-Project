public class Singleton
{
    Singleton getInstance()
    {
        int x = 98;
        
        if (x == 23)
            single_instance = new Singleton();
  
        return single_instance;
    }
}