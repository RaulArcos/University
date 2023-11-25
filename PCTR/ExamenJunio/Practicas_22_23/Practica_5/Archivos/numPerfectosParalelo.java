/**
 * numPerfectosParalelo.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 09/11/2022
 */
 

import java.util.concurrent.*;

public class numPerfectosParalelo {
    public static void main(String[] args) throws Exception{
        int tam = 100000;
        int numHebras = Runtime.getRuntime().availableProcessors();
        int ventana = tam/numHebras;
        int liminf = 0;
        int limsup = ventana;

        long iniciaC = System.nanoTime();

        ThreadPoolExecutor ept = new ThreadPoolExecutor(numHebras, numHebras, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());

        for(int i = 0; i < numHebras; i++){
            ept.submit(new Perfectos(liminf, limsup));
            liminf = limsup + 1;
            limsup = limsup + ventana;
        }
        ept.shutdown();
        while(!ept.isTerminated());
        System.out.println(((System.nanoTime() - iniciaC)/(long)1.0e9) + " s");
   
    }
}

class Perfectos implements Callable {
    private int in;
    private int su;
    private Long total = new Long (0) ;

    public Perfectos (int i, int s){
        this.in = i;
        this.su = s;
    }

    public boolean Perfecto (int n){
        int sum = 0;

        for (int i = 1; i < n; i++)
            if (n % i == 0) sum = sum + i;
        
        if (n == sum)
            return(true);
        return(false);
    }
    public Long call() {
        for (int i = in; i <= su; i++)
            Perfecto(i);
        return (total);
    }
}
