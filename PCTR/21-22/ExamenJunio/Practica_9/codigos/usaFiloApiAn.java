/**
 * usaFiloApiAn.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 19/12/2021
 */

public class usaFiloApiAn implements Runnable{
    public filoApiAN FM;
    public static int filosofos = 5;

    public usaFiloApiAn (filoApiAN FM) {
        this.FM = FM;
    }

    public void run (){
        for (int i = 0; i < filosofos; i++) {
            try {
                FM.takeForks(i);
            } catch (InterruptedException e1) {}
            try {
                FM.releaseForks(i);
            } catch (InterruptedException e2) {}
        }
    }
    
    public static void main (String[] args) throws Exception{
        int fork[] = new int[filosofos];

        for (int i = 0; i < filosofos; i++) fork[i] = 2;

        filoApiAN FM = new filoApiAN(filosofos, fork);

        Thread hebras[] = new Thread[filosofos];

        for (int i = 0; i < filosofos; i++)
            hebras[i] = new Thread (new usaFiloApiAn(FM));

        for (int i = 0; i < filosofos; i++) hebras[i].start();
        for (int i = 0; i < filosofos; i++) hebras[i].join();
    }
}