/**
 * algDekker.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 02/11/2022
 */

 import java.lang.Thread;


public class algDekker extends Thread{
    private int tipoHilo;

    private static volatile boolean C1 = false;
	private static volatile boolean C2 = false;
    private static volatile int turn = 1;

    public algDekker(int tipoHilo)
    {this.tipoHilo = tipoHilo;}

    public void run(){
        while (true) { 
            switch(tipoHilo) {
                case 1: 
                    C1 = true;
                    while (C2) {
                        if (turn == 2) {
                            C1 = false;
                            while (turn == 2);
                            C1 = true;                
                        }
                    }
                    System.out.println(Thread.currentThread().getName());
                    turn = 2;
                    C1 = false;
                break;
                    
                case 2:
                    C2 = true;
                    while (C1) {
                        if (turn == 1) {
                            C2 = false;
                            while (turn == 1);
                            C2 = true;                
                        }
                    }
                    System.out.println(Thread.currentThread().getName());
                    turn = 1;
                    C2 = false;
                break;
                }
        }
    }

    /**
     * Main
     */
    public static void main (String[] args)throws InterruptedException{
        Thread h1 = new algDekker(1);
        Thread h2 = new algDekker(2);
        
        h1.setName("Hilo 1"); h2.setName("Hilo 2");

        h1.start(); h2.start();
        h1.join(); h2.join();
    }

}