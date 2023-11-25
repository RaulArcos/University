/**
 * tiempos.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 14/12/2022
 */

import java.util.concurrent.*;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.atomic.AtomicInteger;

public class tiempos {
    public static ReentrantLock lock = new ReentrantLock();

    public static long syn (int it){
        long ini = System.nanoTime();
        Object o = new Object();
        int n = 0;

        for(int i = 0; i < it; i++){
            synchronized(o){n++;}
        }
        long fin = System.nanoTime();

        return(fin-ini);
    }
    
    public static long sem (int it){
        long ini = System.nanoTime();
        Semaphore s = new Semaphore(1);
        int n = 0;

        for(int i = 0; i < it; i++){
            try{s.acquire();}catch(InterruptedException e){}
            try{n++;}
            finally{s.release();}
        }
        long fin = System.nanoTime();

        return(fin-ini);
    }

    public static long lock (int it) throws InterruptedException{
        long ini = System.nanoTime();
        int n = 0;
        
        lock.lock();

        for( long i = 0; i < it; i ++) {
            lock.lock();
            try { n ++;} finally {lock.unlock(); }
        }
            
        long fin = System.nanoTime();

        return(fin-ini);
    }

    public static long ato (int it){
        long ini = System.nanoTime();
        AtomicInteger c = new AtomicInteger(0);

        for(int i = 0; i < it; i++){
            c.incrementAndGet();
        }
        long fin = System.nanoTime();

        return(fin-ini);
    }

    public static void main(String[] args) throws Exception{

        int it = Integer.parseInt(args[0]);

        System.out.println("Tiempo para synchronized: "+syn(it)+" nanosegundos...");
        System.out.println("Tiempo para semaforos: "+sem(it)+" nanosegundos...");
        System.out.println("Tiempo para lock: "+ lock(it) +" nanosegundos...");
        System.out.println("Tiempo para atomic: "+ato(it)+" nanosegundos...");
    }
        
}
