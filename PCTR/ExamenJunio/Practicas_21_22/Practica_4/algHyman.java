/**
 * algHyman.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 12/11/2021
 */


public class algHyman {
    private static volatile int nVueltas = 10000;
	private static volatile int n = 0;

    private static volatile boolean C1 = false;
	private static volatile boolean C2 = false;

    private static int turn = 1;

    /**
     * Main
     */
    public static void main (String[] args){
        Runnable p1 = () -> {
            for (int i = 0; i < nVueltas; i++){
                C1 = true;
                while (turn != 0){
                    while (C2 == true);
                    turn = 0;
                }
                n++;
                C1 = false;
            }
        };

        Runnable p2 = () -> {
            for (int i = 0; i < nVueltas; i++){
                C2 = true;
                while (turn != 1){
                    while (C1 == true);
                    turn = 1;
                }
                n--;
                C2 = false;
            }
        };

        Thread h1 = new Thread(p1);
        Thread h2 = new Thread(p2);

        h1.start(); h2.start();

        try{
            h1.join(); h2.join();
        } catch (InterruptedException e){}

        System.out.println(n);      
    }
}