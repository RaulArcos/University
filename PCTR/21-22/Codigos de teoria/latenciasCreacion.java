/*
 *@(#) latenciasCreacion.java
 *@author A.T.
 *@version 1.0
*/

import java.util.concurrent.*;

public class latenciasCreacion implements Runnable{
  public void run(){
    for(int i=0; i<100000; i++);
  }
  public static void main(String[] args) throws Exception{
    int nTareas = 1000;	  
    long inicTiempo = System.nanoTime();
    Thread[] h = new Thread[nTareas];
    for(int i=0; i<nTareas; i++)  
      h[i]=new Thread(new latenciasCreacion());
    for(int i=0; i<nTareas; i++)h[i].start();
    for(int i=0; i<nTareas; i++)h[i].join();
    long tiempoTotal = System.nanoTime()-inicTiempo;
    System.out.println("Hilos creados y ejecutados en modo estandar en "+tiempoTotal+" nanosegundos...");
    inicTiempo = System.nanoTime();
    ExecutorService ejecutor = Executors.newCachedThreadPool();
    for(int i=0; i<nTareas; i++)
      ejecutor.execute(new latenciasCreacion());
    ejecutor.shutdown(); 
    while(!ejecutor.isTerminated()){}
    tiempoTotal = System.nanoTime()-inicTiempo;
    System.out.println("Hilos creados y ejecutados con ejecutor en      "+tiempoTotal+" nanosegundos...");
  }

}
