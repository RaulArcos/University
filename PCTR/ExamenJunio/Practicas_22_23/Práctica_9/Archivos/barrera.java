/**
 * barrera.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 14/12/2022
 */

import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.*;

public class barrera extends Thread{
    public CyclicBarrier barrera;
    public int n = 1;

    public barrera(CyclicBarrier barrera){
        this.barrera = barrera;
    }

    public void run () {
        try {
            barrera.await(); 
        } catch (InterruptedException e) {} 
        catch (BrokenBarrierException e) {}
    
        System.out.println(Thread.currentThread().getName());
    }

    public static void main(String[] args) throws Exception {
        CyclicBarrier barrera = new CyclicBarrier(3);
        Thread hebras[] = new Thread[3];

        for (int i = 0; i < 3; i++) hebras[i] = new barrera(barrera);

        for (int i = 0; i < 3; i++) hebras[i].start();
        for (int i = 0; i < 3; i++) hebras[i].join();
    }
}
