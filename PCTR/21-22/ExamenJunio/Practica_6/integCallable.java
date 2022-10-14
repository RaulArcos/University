/**
 * integCallable.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.util.Scanner;
import java.util.*;
import java.util.concurrent.*;

public class integCallable {
    public static void main(String args[]) throws InterruptedException, ExecutionException {
        Vector<Future<Double>> auxFuture = new Vector<Future<Double>>();
        Scanner s = new Scanner(System.in);
        System.out.println("Introduzca el numero de iteraciones a realizar:  ");
        int n = s.nextInt();
        double contador_exitos_sin = 0;

        ExecutorService servicio = Executors.newFixedThreadPool(8);
 
        for (int i = 0; i < 8; i++)
            auxFuture.add(servicio.submit(new iCallable(n)));
        servicio.shutdown();

        for (int i = 0; i < 8; i++)
            contador_exitos_sin = contador_exitos_sin + auxFuture.get(i).get();
        System.out.println("Integral aproximada f(x) = cos(x) -> " + (contador_exitos_sin / n * 8) / 100); 
        s.close();
    }    
}

class iCallable implements Callable <Double>{

    int n = 0;

    public iCallable (int n){
        this.n = n;
    }

    public Double call() throws Exception{
        double contador_exitos_sin = 0;
        for (int i = 0; i < n; i ++) {
            double coordenada_x = Math.random();
            double coordenada_y = Math.random();
            if (coordenada_y <= Math.cos(coordenada_x)) contador_exitos_sin++;
        }
        return contador_exitos_sin;
    }
}
