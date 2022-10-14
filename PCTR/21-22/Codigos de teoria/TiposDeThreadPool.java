import java.util.concurrent.*;

class Tarea implements Runnable
{
  private int nVueltas = 10;
  private static int cHilos   =  0;
  public Tarea(){}
  public void run()
  {
    cHilos++; 	  
    for(int i=0; i<nVueltas;i ++)
      System.out.println("Hilo numero "+cHilos+ " imprimiendo...");
  }
}

public class TiposDeThreadPool
{
  public static void main(String[] args)
  {
    ExecutorService ejecutor = Executors.newCachedThreadPool();
    for(int i=0; i<10; i++) ejecutor.execute(new Tarea());
    ejecutor.shutdown();
    
    ejecutor = Executors.newFixedThreadPool(5);
    for(int i=0; i<10; i++) ejecutor.execute(new Tarea());
    ejecutor.shutdown();
    
    ejecutor = Executors.newSingleThreadExecutor();
    for(int i=0; i<10; i++) ejecutor.execute(new Tarea());
    ejecutor.shutdown();
  }
}

