/**
 * @(#)hConcu.java
 * @author A.T.
 * @version 1.00 2014/10/25
 * HEBRAS QUE COMPARTEN MEMORIA ENCAPSULADA EN UN OBJETO 
 */

public class hConcu
  extends Thread
{   private Critica c;

    public hConcu(Critica c)
    {this.c=c;}

    public void run()
    {
      for(int i=0; i<10000; i++)c.inc();
    }
    public static void main(String[] args)
      throws Exception
    {
      Critica p  = new Critica(); //referencia a objeto comun...
      hConcu  h1 = new hConcu(p); //ambos hilos comparten el acceso a p
      hConcu  h2 = new hConcu(p); // a traves de la referencia
      h1.start(); h2.start();
      h1.join(); h2.join();
      System.out.println(p.vDato());
    }
}
