/**
 * algDekker.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 12/11/2021
 */


public class algDekker extends Thread{
    private int tipoHilo;
    private static volatile int nVueltas = 10000;
	private static volatile int n = 0;

    private static volatile boolean C1 = false;
	private static volatile boolean C2 = false;

    private static int turn = 1;

    public algDekker(int tipoHilo)
    {this.tipoHilo=tipoHilo;}

    public void run(){
        for (int i = 0; i < nVueltas; i ++) {
            switch(tipoHilo){
                case 1:{
                    C1 = true;
                    turn = 2;
                    while ((C2 == true) && (turn == 2));
                    n++;
                    C1 = false;
                }break;
                    
                case 2: {
                    C2 = true;
                    turn = 1;
                    while ((C1 == true) && (turn == 1));
                    n--;
                    C2 = false;
                }break;
            }
        }
    } 

    /**
     * Main
     */
    public static void main (String[] args)throws InterruptedException{
        Thread h1 = new algDekker(1);
        Thread h2 = new algDekker(2);
        
        h1.start(); h2.start();
        h1.join(); h2.join();
        System.out.println(n);
    }

}