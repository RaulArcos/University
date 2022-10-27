/**
 * Usa_tareaRunnable.java
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class Usa_tareaRunnable {
    public static void main(String[] arg) throws Exception {
        Critica p  = new Critica(); //referencia a objeto comun...
        tareaRunnable  h1 = new tareaRunnable(p,0); //ambos hilos comparten el acceso a p
        tareaRunnable  h2 = new tareaRunnable(p,1); // a traves de la referencia
        h1.start(); h2.start();
        h1.join(); h2.join();
        System.out.println(p.vDato());
    }
}
