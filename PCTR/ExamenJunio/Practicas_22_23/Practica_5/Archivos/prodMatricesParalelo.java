/**
 * prodMatricesParalelo.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 09/11/2022
 */

import java.util.concurrent.*;

public class prodMatricesParalelo {
    public static void main (String[] arg) throws Exception{

        int tam = 1000;
        int m1[][] = new int [tam][tam];
        int m2[][] = new int [tam][tam];

        int m[][] = new int [tam][tam];
        int res = 0;

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++){
                m1[i][j] = 1;
                m2[i][j] = 1;
            }
        }

        int numHebras = Runtime.getRuntime().availableProcessors();
        int ventana = tam/numHebras;
        int liminf = 0;
        int limsup = ventana;

        long iniciaC = System.nanoTime();

        ThreadPoolExecutor ept = new ThreadPoolExecutor(numHebras, numHebras, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());

        for(int i = 0; i < numHebras; i++){
            ept.execute(new tareaProdMatrices(liminf, limsup, m1, m2, m, res));
            liminf = limsup + 1;
            limsup = limsup + ventana;
        }
        ept.shutdown();
        while(!ept.isTerminated());
        System.out.println(((System.nanoTime() - iniciaC)/(long)1.0e9) + " s");   
    }
}

class tareaProdMatrices implements Runnable{
    private int tam = 1000;    
    private int in;
    private int su;
    private int r = 0;

    private int m1[][] = new int [tam][tam];
    private int m2[][] = new int [tam][tam];
    private int m[][] = new int [tam][tam];

    public tareaProdMatrices(int li, int ls, int m1[][], int m2[][], int m[][], int res){
        this.in = li;
        this.su = ls;
        this.r = res;
        this.m1 = m1;
        this.m2 = m2;
        this.m = m;
    }

    public void run(){
        for (int i = in; i < su; i++){
            for (int j = in; j < su; j++){
                r = 0;
                for (int k = 0; k < tam; k++)
                    r = r + (m1[j][k] * m2[k][i]);
                m[j][i] = r;
            }
        }
    }
}
