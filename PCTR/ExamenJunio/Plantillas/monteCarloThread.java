import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.*;
import java.util.*;

public class monteCarloThread extends Thread {
    private static double intParcial = 0;
    private Object obj;
    private int seed, nPuntos, linf, lsup;

    //Constructor con el numero de puntos y la semilla
    public monteCarloThread(int nP, int s, int li, int ls) {
        nPuntos = nP;
        seed = s;
        linf = li;
        lsup = ls;
    }

    //Funcion que hace cosas
    public static double f(double x) {/*Hace cosas */}

    public void run() {
        double ip = 0;
        Random r = new Random(seed);

        //Siempre es lo mismo, tirar puntos randoms
        for (int i = 0; i < nPuntos; i++) {
            double x = linf + (lsup-linf)*r.nextDouble(); //para q se repartan entre los limites
            double y = r.nextDouble();
            if (y <= f(x)) ip++; //Sumar los puntos por debajo
        }
        ip = ip / nPuntos;

        //EM mediante synchronized
        synchronized(obj){  
            intParcial += ip;
        }
    }

    public static void main(String[] args) throws Exception{
        //Definir numero de puntos
        int nPuntos = 18000000; 

        //Vector de thread
        int numHebras = 5;
        Thread hebras[] = new Thread[numHebras]; //creamos el vector
        
        
        //En secuencial:
        for (int i = 0; i < numHebras; i++) hebras[0] = new Thread(new monteCarloThread(nPuntos, r.nextInt(), 0, numHebras)); //rellenamos el vector con el constructor de la clase
        for (int i = 0; i < numHebras; i++) hebras[0].start();
        for (int i = 0; i < numHebras; i++) hebras[0].join();

        double areaSec = intParcial;
        intParcial = 0;

        //Paralelo:
        for (int i = 0; i < numHebras; i++) hebras[i] = new Thread(new monteCarloThread(nPuntos, r.nextInt(), i, i+1)); //rellenamos el vector con el constructor de la clase
        for (int i = 0; i < numHebras; i++) hebras[i].start();
        for (int i = 0; i < numHebras; i++) hebras[i].join();
    }
}