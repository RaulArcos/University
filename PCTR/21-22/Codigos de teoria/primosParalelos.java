import java.util.concurrent.*;
import java.util.*;

public class primosParalelos {

  public static void main(String[] args) throws Exception {
    long nPuntos     = Integer.parseInt(args[0]);
    int  nTareas     = Runtime.getRuntime().availableProcessors();
    long tVentana    = nPuntos/nTareas;
    long primosTotal = 0;
    long linf        = 0;
    long lsup        = tVentana;
    
    ArrayList<Future<Long>> contParciales =
      new ArrayList<Future<Long>>();
    long inicTiempo = System.nanoTime();  
    ThreadPoolExecutor ept = new ThreadPoolExecutor(
      nTareas,
      nTareas,
      0L,
      TimeUnit.MILLISECONDS,
      new LinkedBlockingQueue<Runnable>());
    for(int i=0; i<nTareas; i++){
      contParciales.add(ept.submit(
      	 new tareaPrimos(linf, lsup)));
      linf=lsup;
      lsup+=tVentana;
    }  
    for(Future<Long> iterador:contParciales)
      try{
      	  primosTotal +=  iterador.get(); 
      }catch (CancellationException e){}
       catch (ExecutionException e){}
       catch (InterruptedException e){}     
    long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e9;   
    ept.shutdown();
    System.out.println("Primos hallados: "+primosTotal);
    System.out.println("Calculo finalizado en "+tiempoTotal+" segundos");
 }   
}
