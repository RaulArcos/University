import java.util.*;
import java.util.concurrent.*;

public class pruebaLife
    implements Runnable
{
    Life ob = new Life();
    static CyclicBarrier cb;
    private int hilo, fila;
    
    public pruebaLife(int h, int f)
    {
	hilo = h;
	fila = f;
    }

    public void run()
    {
	Thread h = Thread.currentThread();

	for(int i = 0; i < 100; ++i) {
	    ob.nextGen(fila);
	    System.out.println("Soy el hilo " + hilo + ", mi prioridad es " + h.getPriority() + " y el status actual es " + ob.status() + " celulas vivas. ");
	}
	try {
	    cb.await();
	}catch (Exception e) {}
    }

    public static void main(String[] args)
	throws Exception
    {
	cb = new CyclicBarrier(10);

	ExecutorService pool = Executors.newFixedThreadPool(10);

	for(int i = 0; i < 10; ++i)
	    pool.execute(new pruebaLife(i, i));

	pool.shutdown();

	while(!pool.isTerminated());
    }
}