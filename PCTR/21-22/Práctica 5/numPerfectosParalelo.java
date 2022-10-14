import java.util.concurrent.*;
import java.util.*;

public class numPerfectosParalelo 
{
    public static void main(String[] args) throws Exception 
    {
    	
        long nPuntos = Integer.parseInt(args[0]);
        int nTareas = 16;
        long tVentana = nPuntos/nTareas;
    	long total = 0;
    	long linf = 0;
    	long lsup = tVentana;

        ArrayList<Future<Long>> cont = new ArrayList<Future<Long>>();
        
        long inicTiempo = System.nanoTime();  
    	
        ThreadPoolExecutor ept = new ThreadPoolExecutor(nTareas, nTareas, 0L, 
    				TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());
    	 
    	for(int i = 0; i < nTareas; i++)
    	{
    		cont.add(ept.submit(new tareaPerf(linf, lsup)));
    		linf = lsup + 1;
    		lsup += tVentana;
    	}
    	
    	for(Future<Long> i : cont)
    		try
      		{
      			total += i.get(); 
    		}catch (CancellationException e){}
    		 catch (ExecutionException e){}
    		 catch (InterruptedException e){}
    	
    	ept.shutdown();

        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("Encontrados " + total + " en " + tiempoTotal + " ms");
    	
    }
}

class tareaPerf implements Callable{
   
	private  long linf;
	private  long lsup;
	//private Long total = new Long(0);	//Derogado
	private long total = 0;
	 	
	public tareaPerf(long linf, long lsup)
	{
		this.linf = linf;
		this.lsup = lsup;
	}
		
	public Long call()
	{
        long sum = 0;
        for(long i = linf; i <= lsup; i++)
        {
            sum = 0;
            for(long j = 1; j < i; j++)
                if(i % j == 0) sum += j;
            if(i == sum)
                total++;
        }
		return(Long.valueOf(total));
	}
}
