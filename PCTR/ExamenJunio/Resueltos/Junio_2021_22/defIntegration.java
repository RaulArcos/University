import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.*;
import java.util.*;

public class defIntegration implements Runnable {
    private static double intParcial = 0;
    private static Semaphore lock = new Semaphore(1);
    private int seed, nPuntos;

    public defIntegration(int nP, int s) {
        nPuntos = nP;
        seed = s;
    }

    public static double f(double x) {
        return 2 * Math.pow(x, 4) / (3 * Math.pow(x, 6) + 3);
    }

    public void run() {
        double ip = 0;
        Random r = new Random(seed);
        for (int i = 0; i < nPuntos; i++) {
            double x = r.nextDouble() * 6;
            double y = r.nextDouble();
            if (y <= f(x)) ip++;
        }
        ip = ip / nPuntos;
        try {
            lock.acquire();
            intParcial += ip;
        } catch (InterruptedException e) {e.printStackTrace();} finally {lock.release();}
    }

    public static void main(String[] args) throws Exception{
        int nPuntos = 18000000;
        double ipS = 0;
        Random r = new Random();
        double intSecuencial = 0;
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(6);
        long tiempoInicioSecuencial = System.nanoTime();
        
        for (int j = 0; j < 6; j++) {
            ipS = 0;
            for (int i = 0; i < nPuntos; i++) {
                double x = r.nextDouble() * 6;
                double y = r.nextDouble();
                if (y <= f(x)) ipS++;
            }
            ipS = ipS / nPuntos;
            intSecuencial += ipS;
        }
        
        long tiempoSecuencial = System.nanoTime() - tiempoInicioSecuencial;

        long tiempoInicioParalelo = System.nanoTime();
        for (int i = 0; i < 6; i++) {
            ept.execute(new defIntegration(nPuntos/6, r.nextInt()));
            Thread.sleep(100);
        }
        ept.shutdown();
        while(!ept.isShutdown()) ept.awaitTermination(10, TimeUnit.SECONDS);
        long tiempoParalelo = System.nanoTime() - tiempoInicioParalelo;

        System.out.println("Tiempo de ejecucion paralelo: " + tiempoParalelo + " ns");
        System.out.println("Tiempo de ejecucion secuencial: " + tiempoSecuencial + " ns");
        System.out.println("Integral secuencial: " + intSecuencial);
        System.out.println("Integral paralelo: " + intParcial);
        System.out.println("Speedup: " + (double) tiempoSecuencial / tiempoParalelo);
    }
}