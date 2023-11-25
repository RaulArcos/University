/**
 * usaheterogenea.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 15/11/2022
 */

public class usaheterogenea extends Thread{
    private heterogenea het;
    public static int rep = 10000;

    public usaheterogenea (heterogenea h){
        this.het = h;
    }

    public void run(){
        for (int i = 0; i < rep; i++){
            het.incs();
            het.inc();
        }
    }

    public static void main (String[] args) throws Exception {
        heterogenea het = new heterogenea();

        Thread A = new Thread (new usaheterogenea(het));
        Thread B = new Thread (new usaheterogenea(het));

        A.start(); B.start();
        A.join(); B.join();

        System.out.println(het.n());
        System.out.println(het.m());
    }
    
}
