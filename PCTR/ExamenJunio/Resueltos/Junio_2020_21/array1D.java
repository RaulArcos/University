import java.util.concurrent.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

public class array1D implements Runnable {
    public static int t = 200, n = (int)10e6;
    public static int r[] = new int [n];
    private static int start, end;

    public array1D (int s, int e) {
        start = s;
        end = e;
    }

    public synchronized void run(){
        for (int i_t = 0; i_t < t; i_t++) {
            for (int i = start; i < end; i++) {
                if ((i - 1) < 0) {
                    r[i] = ((0 - 0) * 10 + r[i + 1]);
                } else if ((i - 2) < 0) {
                    r[i] = ((0 - r[i - 1]) * 10 + r[i + 1]);
                } else if ((i + 1) >= n) {
                    r[i] = ((r[i - 2] - r[i - 1]) * 10 + 0);
                } else {
                    r[i] = ((r[i - 2] - r[i - 1]) * 10 + r[i + 1]);
                }
            }
        }
    }

    public static void main (String[] args) throws Exception{
        Scanner s = new Scanner(System.in);
        Random ran = new Random();
        System.out.println ("Introduzca el numero de hebras deseado para la ejecucion paralela: ");
        int numHebras = s.nextInt();
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(numHebras);
        ThreadPoolExecutor eptSec = (ThreadPoolExecutor)Executors.newFixedThreadPool(1);

        for (int i = 0; i < n; i++) r[i] = ran.nextInt(6);

        long iniTimeSec = System.nanoTime();
        eptSec.execute(new array1D(0, n));
        eptSec.shutdown();
        while(!eptSec.isShutdown()) eptSec.awaitTermination(10, TimeUnit.SECONDS);
        long finTimeSec = System.nanoTime() - iniTimeSec;

        int start = 0, desp = n / numHebras, end = desp; 
        long iniTimePar = System.nanoTime();

        for (int i = 0; i < numHebras; i++) {
            ept.execute(new array1D(start, end));
            Thread.sleep(10);
            start = end;
            end = end + desp;
        }

        ept.shutdown();
        while(!ept.isShutdown()) ept.awaitTermination(10, TimeUnit.SECONDS);

        long finTimePar = System.nanoTime() - iniTimePar;

        System.out.println ("Tiempo de ejecución secuencial: " + finTimeSec + " ns.");
        System.out.println ("Tiempo de ejecución paralelo: " + finTimePar + " ns.");
        System.out.println ("SpeedUp: " + ((double)(finTimeSec/finTimePar) / 1e9));

        s.close();        
    }
}
