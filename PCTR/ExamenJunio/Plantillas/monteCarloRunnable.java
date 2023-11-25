import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.*;
import java.util.*;

public class monteCarloRunnable implements Runnable {
    private static double intParcial = 0;
    private static Semaphore lock = new Semaphore(1);
    private int seed, nPuntos;

    //Constructor con el numero de puntos y la semilla
    public monteCarloRunnable(int nP, int s) {
        nPuntos = nP;
        seed = s;
    }

    //Funcion que hace cosas
    public static double f(double x) {/*Hace cosas */}

    public void run() {
        double ip = 0;
        Random r = new Random(seed);

        //Siempre es lo mismo, tirar puntos randoms
        for (int i = 0; i < nPuntos; i++) {
            double x = r.nextDouble() * 6; //6 porque lo dividimos en 6 intervalos [0, 6]
            double y = r.nextDouble();
            if (y <= f(x)) ip++; //Sumar los puntos por debajo
        }
        ip = ip / nPuntos;

        //EM mediante cerrojo
        try {
            lock.acquire();
            intParcial += ip;
        } catch (InterruptedException e) {e.printStackTrace();} finally {lock.release();}
    }

    public static void main(String[] args) throws Exception{
        //Definir numero de puntos
        int nPuntos = 18000000; 
        //Pool de thread
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(6);
        
        //En secuencial:
        for (int j = 0; j < 6; j++) {
            ipS = 0;
            for (int i = 0; i < nPuntos; i++) {
                double x = r.nextDouble() * 6; //6 porque lo dividimos en 6 intervalos [0, 6]
                double y = r.nextDouble();
                if (y <= f(x)) ipS++;
            }
            ipS = ipS / nPuntos;
            intSecuencial += ipS;
        }
       
        //Ejecutar pool de Thread para semillas diferentes
        for (int i = 0; i < 6; i++) {
            ept.execute(new defIntegration(nPuntos/6, r.nextInt()));
            Thread.sleep(100);
        }
        ept.shutdown();
        while(!ept.isShutdown()) ept.awaitTermination(10, TimeUnit.SECONDS);
    }
}