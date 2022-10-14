/**
 * @author Raúl Arcos Herrera
 * 
*/
public class hetereogenea 
{
    public static int n = 0;
    public static int m = 0;

    public synchronized void aumento_synchronized(){n++;}
    public void aumento_unsynchronized(){m++;}
}
