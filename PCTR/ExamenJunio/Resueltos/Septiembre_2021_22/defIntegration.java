import java.util.concurrent.*;
import java.util.*;

public class defIntegration extends Thread {
    private static double areaParcial = 0;
    private static Object obj;
    private int seed, nPuntos, linf, lsup;

    public defIntegration(Object o, int nP, int s, int li, int ls) {
        obj = o;
        nPuntos = nP;
        seed = s;
        linf = li;
        lsup = ls;
    }

    //Funcion que hace cosas
    public static double f(double x) {return (Math.pow(x, 5) + 1) / (3 * Math.pow(x, 6) + 6);}

    public void run() {
        double ip = 0;
        Random r = new Random(seed);

        for (int i = 0; i < nPuntos; i++) {
            double x = linf + (lsup-linf) * r.nextDouble();
            double y = r.nextDouble();
            if (y <= f(x)) ip++;
        }
        ip = ip / (nPuntos / (lsup-linf));

        //EM mediante synchronized
        synchronized(obj){  
            areaParcial += ip;
        }
    }

    public static void main(String[] args) throws Exception{
        Object obj = new Object();
        int nPuntos = 15000000; 
        int numTareas = 5;
        Thread task[] = new Thread[numTareas]; 
        Random r = new Random();
        double areaParcialSec = 0;
        long tIniSec, tSec, tIniPar, tPar;
        
        //En secuencial:
        task[0] = new Thread(new defIntegration(obj, nPuntos, r.nextInt(), 0, 5));

        tIniSec = System.nanoTime();
        task[0].start(); task[0].join();
        tSec = System.nanoTime() - tIniSec;

        areaParcialSec = areaParcial;
        areaParcial = 0;

        //Paralelo:
        for (int i = 0; i < numTareas; i++) task[i] = new Thread(new defIntegration(obj, nPuntos / 5, r.nextInt(), i, i+1));
        tIniPar = System.nanoTime();
        for (int i = 0; i < numTareas; i++) task[i].start();
        for (int i = 0; i < numTareas; i++) task[i].join();
        tPar = System.nanoTime() - tIniPar;

        System.out.println ("Tiempo secuencial: " + tSec + " nanosegundos");
        System.out.println ("Tiempo paralelo: " + tPar + " nanosegundos");
        System.out.println ("Integracion secuencial: " + areaParcialSec);
        System.out.println ("Integracion paralela: " + areaParcial);
        System.out.println ("Speedup: " + (tSec / tPar));
    }
}