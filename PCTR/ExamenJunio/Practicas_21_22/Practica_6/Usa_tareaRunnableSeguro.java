/**
 * Usa_tareaRunnableSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

public class Usa_tareaRunnableSeguro{

    public static void main(String[] args) throws Exception {
    Critica p  = new Critica();
    Object obj = new Object();

    tareaRunnableSeguro r1 = new tareaRunnableSeguro(p, 0, obj);
    tareaRunnableSeguro r2 = new tareaRunnableSeguro(p, 1, obj);
    
    Thread  h1 = new Thread(r1);
    Thread  h2 = new Thread(r2);
    h1.start();
    h2.start();
    h1.join();
    h2.join();
    
    System.out.println(p.vDato());
  }
}