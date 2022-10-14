/**
 * monitorImpresion.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 4/12/2021
 */

public class monitorImpresion {
    public int i, impresoras;
    public boolean libre[] = new boolean[impresoras];

    public monitorImpresion (int impresoras, boolean libre[]){
        this.impresoras = impresoras;
        this.libre = libre;        
    }

    public synchronized int take_print() {
        while (impresoras == 0) {try { wait(); } catch (InterruptedException e) {} }
        int aux = 0;
        while (!libre[aux]) aux++;
        libre[aux] = false;
        impresoras++;
        return aux;
    }
  
    public synchronized void drop_print (int n) {
        libre[n] = true;
        impresoras++;
        notifyAll();
    }
}
  