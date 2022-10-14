import java.util.concurrent.*;
import java.util.*;

class tareaConResultado implements Callable
{
  private int iden;
  public tareaConResultado (int id){iden=id;}
  public String call(){return("Resultado de la tarea "+iden);}
}	

public class pruebaCallable
{
  public static void main(String[] args)
  {
   ExecutorService ejecutor = Executors.newCachedThreadPool();
   ArrayList<Future<String>> resultados = new ArrayList<Future<String>>();
    for(int i=0; i<10; i++) 
      resultados.add(ejecutor.submit(new tareaConResultado(i)));

   for(Future<String> iter: resultados)
     try{
     	  System.out.println(iter.get());    
     }catch (InterruptedException e){}
      catch (ExecutionException e){}
   ejecutor.shutdown();  
  }	  
}
