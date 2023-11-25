/**
 * resImagenPar.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 09/11/2022
 */

import java.util.*;
import java.util.concurrent.*;

public class resImagenPar {
    public static void main (String[] args) throws Exception{
        int tam = 10000;
        int m[][] = new int[tam][tam];

        Random r = new Random();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++)
                m[i][j] = r.nextInt() % 255;
        }

        int numHebras = Runtime.getRuntime().availableProcessors();
        int ventana = tam/numHebras;
        int liminf = 0;
        int limsup = ventana;

        long iniciaC = System.nanoTime();

        ThreadPoolExecutor ept = new ThreadPoolExecutor(numHebras, numHebras, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());

        for(int i = 0; i < numHebras; i++){
            ept.execute(new tareaResImagen(liminf, limsup, m));
            liminf = limsup + 1;
            limsup = limsup + ventana;
        }

        ept.shutdown();
        while(!ept.isTerminated());
        System.out.println(((System.nanoTime() - iniciaC)/(long)1.0e9) + " s");
    }
}

class tareaResImagen implements Runnable {
    private int tam = 10000;    
    private int in;
    private int su;

    private int m[][] = new int [tam][tam];

    public tareaResImagen (int i, int s, int m[][]){
        this.in = i;
        this.su = s;
        this.m = m;
    }

    public void run() {
        for (int i = in; i < su; i++){
            for (int j = 0; j < tam; j++){
                m[i][j] = m[i][j] * 4;

                if (i - 1 >= 0) m[i][j] = m[i][j] - m[i - 1][j];
                if (i + 1 < tam) m[i][j] = m[i][j] - m[i + 1][j];                
                if (j - 1 >= 0) m[i][j] = m[i][j] - m[i][j - 1];
                if (j + 1 < tam) m[i][j] = m[i][j] - m[i][j + 1];

                m[i][j] = m[i][j] / 8;
            }
        }
    }
}