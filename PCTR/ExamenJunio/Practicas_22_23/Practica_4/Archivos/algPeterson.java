/**
 * algPeterson.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 02/11/2022
 */

import java.lang.Thread;

public class algPeterson implements Runnable {
    private int tipoHilo;

    private static volatile boolean C1 = false;
	private static volatile boolean C2 = false;
    private static int turn = 1;


    public algPeterson (int tipoHilo) 
    {this.tipoHilo = tipoHilo;}

    /**
     * Run
     */

    public void run () {
        while (true) {
            switch (tipoHilo) {
                case 1:
                    C1 = true;
                    turn = 1;
                    while (C2 == false && turn == 2);
                    System.out.println(Thread.currentThread().getName());
                    C1 = false;
                break;
                case 2:
                    C2 = true;
                    turn = 2;
                    while (C1 == false && turn == 1);
                    System.out.println(Thread.currentThread().getName());
                    C2 = false;
                break;
            }
        }
    }

    /**
     * Main
     */
    public static void main (String[] args) throws InterruptedException {      
        Thread h1 = new Thread (new algPeterson(1));
        Thread h2 = new Thread (new algPeterson(2));

        h1.setName("Hilo 1"); h2.setName("Hilo 2");

        h1.start(); h2.start();
        h1.join(); h2.join();
    }
}
