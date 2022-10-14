/**
 * @(#)incConcurrenteSeguro.java
 *
 *
 * @author A.T.
 * @version 1.00 2013/05/20
 */

public class incConcurrenteSeguro
  extends Thread
{
   private static int    n     = 0;
   private static Object lock  = new Object();
   private int nIter;

    public incConcurrenteSeguro(int v) {nIter=v;}
    public void run()
    {
    	for(int i=1;i<=nIter;i++) synchronized(lock){n++;}

    }
    public static void main(String[] args)
      throws InterruptedException
    {
    	int p = 100;
        incConcurrenteSeguro[] h = new incConcurrenteSeguro[p];
        for(int i=0;i<h.length;i++)h[i] = new incConcurrenteSeguro(1000);
        for(int i=0;i<h.length;i++)h[i].start();
        for(int i=0;i<h.length;i++)h[i].join();
        System.out.print(n);
    }
}
