/**
 * LambdaSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

public class LambdaSeguro{
    public static int critica = 0;

    public static void main (String[] args) throws Exception{
        Object obj = new Object();

        Runnable r1 = () -> { synchronized(obj){ { for(int i = 0; i < 10000; ++i) ++critica; } } };
        Runnable r2 = () -> { synchronized(obj){ { for(int i = 0; i < 10000; ++i) --critica; } } };
        
        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);

        t1.start();
        t2.start();
		t1.join();
        t2.join();

        System.out.println(critica);
    }
}