/**
 * deadlock.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 15/11/2022
 */

public class deadlock extends Thread{
    public static int n = 0;
    private Object obj;
    private Object obj2;

    public deadlock (Object obj, Object obj2){
        this.obj = obj;
        this.obj2 = obj2;
    }

    public void run(){
        synchronized(obj){
            for(int i = 0; i < 100000; i++);
                synchronized(obj2){
                    System.out.println(n);
                }
        }
    }
    public static void main(String[] args) throws Exception {
        Object region_A = new Object();
        Object region_B = new Object();
        Object region_C = new Object();

        Thread Hilo_A = new Thread (new deadlock(region_A, region_C));
        Thread Hilo_B = new Thread (new deadlock(region_B, region_A));
        Thread Hilo_C = new Thread (new deadlock(region_C, region_B));
    
        Hilo_C.start(); Hilo_B.start(); Hilo_A.start();
        Hilo_C.join(); Hilo_B.join(); Hilo_A.join();
    }
}
