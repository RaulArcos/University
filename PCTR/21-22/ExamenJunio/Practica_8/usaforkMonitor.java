/**
 * usaforkMonitor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 4/12/2021
 */

import java.lang.Exception;

public class usaforkMonitor extends Thread{
    public forkMonitor FM;
    public static int filosofos = 5;

    public usaforkMonitor (forkMonitor FM) {
        this.FM = FM;
    }

    public void run (){
        for (int i = 0; i < filosofos; i++) {
            FM.takeForks(i);
            FM.releaseForks(i);
        }
    }
    
    public static void main (String[] args) throws Exception{
        int fork[] = new int[filosofos];
        for (int i = 0; i < filosofos; i++) fork[i] = 2;

        forkMonitor FM = new forkMonitor(filosofos, fork);

        Thread hebras[] = new Thread[filosofos];

        for (int i = 0; i < filosofos; i++)
            hebras[i] = new Thread (new usaforkMonitor(FM));

        for (int i = 0; i < filosofos; i++) hebras[i].start();
        for (int i = 0; i < filosofos; i++) hebras[i].join();
    }
}
