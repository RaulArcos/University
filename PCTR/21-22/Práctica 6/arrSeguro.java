import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Raúl Arcos Herrera
 * 
*/
public class arrSeguro extends Thread
{
    public static int n = 0;
    public static int nHebras = 10;
    public static int[] v;
    private Object lock = new Object();
    public static Object Monitor = new Object();

    arrSeguro(Object Mon)
    {
        lock = Mon;
    }

    public void run()
    {
        synchronized(lock)
        {
            for(int i=0; i<n; i++)
                for(int j=0; j<10000; j++)
                    v[i]++;
        }
    }

    public static void main(String[] args) throws Exception
    {
        System.out.print("Introduce el tamano del vector = ");
        Scanner in =  new Scanner(System.in);
        n = in.nextInt();
        in.close();

        v = new int[n];
        
        Thread[] hilos = new Thread[nHebras];
        for(int i = 0; i < nHebras; i++) 
            hilos[i] = new arrSeguro(Monitor);
        
        for(int i = 0; i < nHebras; i++)
            hilos[i].start();
        for(int i = 0; i < nHebras; i++)
            hilos[i].join();
        
        System.out.print("Resultado = " + Arrays.toString(v));


    }
}
