import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.*;
import java.util.*;

public class intDefinida implements Callable <Double> {
    private int seed, linf, lsup, nPuntos;

    //Constructor con el numero de puntos y la semilla
    public intDefinida (int nP, int s, int li, int ls) {
        nPuntos = nP;
        seed = s;
        linf = li;
        lsup = ls;
    }

    //Funcion que hace cosas
    public static double f(double x) {/*Hacer cosas */}

    public Double call () {
        double ip = 0;
        Random r = new Random(seed);

        //Siempre es lo mismo, tirar puntos randoms
        for (int i = 0; i < nPuntos; i++) {
            double x = linf + (lsup-linf)*r.nextDouble(); //para q se repartan entre los limites
            double y = r.nextDouble();
            if (y <= f(x)) ip++; //Sumar los puntos por debajo
        }
        ip = ip / (nPuntos/(lsup - linf));
        
        return ip;
    }

    public static void main(String[] args) throws Exception{
        int nPuntos = 100000000, nTareas = 4; 
        Random r = new Random();
        Vector<Future<Double>> intervalos = new Vector<Future<Double>>();
        Vector<Future<Double>> intervalosSec = new Vector<Future<Double>>();
        double integralSec = 0, integral = 0;

        //En secuencial
        ThreadPoolExecutor etpSec = (ThreadPoolExecutor)Executors.newFixedThreadPool(1);

        intervalosSec.addElement(etpSec.submit(new intDefinida ((nPuntos), r.nextInt(), 0, nTareas)));
            
        etpSec.shutdown();
        while(!etpSec.isTerminated());

        //En paralelo
        ThreadPoolExecutor etp = (ThreadPoolExecutor)Executors.newFixedThreadPool(nTareas);

        for (int i = 0; i < nTareas; i++) intervalos.addElement(etp.submit(new intDefinida (nPuntos, r.nextInt(), i, i+1)));  

        etp.shutdown();
        while(!etp.isTerminated());
    
        try {integralSec = intervalosSec.get(0).get();} catch (InterruptedException e){} catch (ExecutionException e) {}
        try {for (int i = 0; i < nTareas; i++) integral = integral + intervalos.get(i).get();} catch (InterruptedException e){} catch (ExecutionException e) {}
    }
}