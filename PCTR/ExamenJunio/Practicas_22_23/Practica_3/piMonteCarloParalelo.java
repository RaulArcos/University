
public class piMonteCarloParalelo extends Thread{
  private double cx, cy;
  private static int intentos = 0;
  private static Object lock = new Object();
  private long vueltas;
  
  public piMonteCarloParalelo(long n)
  {vueltas = n;}
  
  public void run(){
    for(long i=0; i<vueltas; i++){
      cx = Math.random();
      cy = Math.random();
      if(Math.sqrt(Math.pow(cx, 2)+Math.pow(cy, 2))<=1)
        synchronized(lock){intentos++;}
    }
  }
  
  public static void main(String[] args) throws Exception{
    long nVueltas   = 100000000;
    int nThreads    =      2000;
    long inicTiempo = System.nanoTime();
    piMonteCarloParalelo[] h = new piMonteCarloParalelo[nThreads];
    for(int i=0; i<nThreads; i++)h[i]=new piMonteCarloParalelo((int)(nVueltas/nThreads));
    for(int i=0; i<nThreads; i++)h[i].start();
    for(int i=0; i<nThreads; i++)h[i].join();
    long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e9;
    System.out.println("Aproximacion: "+4.0*intentos/nVueltas);
    System.out.println("Valor Real: "+Math.PI);
    System.out.println("en "+tiempoTotal+" segundos...");
  }
}
