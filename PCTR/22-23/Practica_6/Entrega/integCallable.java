import java.util.concurrent.*;
import java.util.*;

/**
 * @author Raúl Arcos Herrera
 * 
*/
public class integCallable { 
    
    

    public static double f_sin(double x)
    {
        return Math.sin(x);
    }

    public static void main(String[] args) throws Exception 
    {   
        double total = 0;
        System.out.print("Introduce el numero de iteraciones: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();

        int nTareas = 8;

        ArrayList<Future<Double>> cont = new ArrayList<Future<Double>>();
        
        ThreadPoolExecutor ept = new ThreadPoolExecutor(nTareas, nTareas, 0L, 
        TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());

        for(int i = 0; i < nTareas; i++)
        {
        cont.add(ept.submit(new tarea(n)));
        }

        for(Future<Double> i : cont)
        try
        {
            total += i.get(); 
        }catch (CancellationException e){}
        catch (ExecutionException e){}
        catch (InterruptedException e){}

        ept.shutdown();

        System.out.println("Integral aproximada sin= " + total/nTareas);
        
    }
}

class tarea implements Callable{

    private int n_ = 0;
	private double contador_exitos_ = 0;

	public tarea(int n)
	{
		n_ = n;
	}
		
	public Double call()
	{
        for (int i = 0; i < n_; i++)
        {
            double coordenada_x =  Math.random();
            double coordenada_y =  Math.random();

            if(coordenada_y <= Math.sin(coordenada_x))
            {
                contador_exitos_++;
            }
        }
        return contador_exitos_/n_;                                                             
	}
}
