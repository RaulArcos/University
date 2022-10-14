/**
 * drakkarVikingo.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 2/12/2021
 */

public class drakkarVikingo {
    private int m;

    public drakkarVikingo (int  m){
        this.m = m;
    }

    public synchronized void comer() {
        while (m == 0){
            System.out.println("Se ha vaciado la marmita, llamar al cocinero");
            notifyAll();
            try{ wait(); } catch (InterruptedException e) {}
        }
        m--;
    }

    public synchronized void cocinar(){
        while (m > 0){
            try { wait(); } catch (InterruptedException e) {}
        }
        m++;
        System.out.println("Marmita rellena, toca comer");
        notifyAll();
        
    }
}