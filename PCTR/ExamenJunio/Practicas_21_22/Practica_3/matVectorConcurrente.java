/**
 * prodEscalar.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 05/11/2021
 */

import java.util.*;

public class matVectorConcurrente implements Runnable {

    static int tam = (int)Math.pow(10,4);
    private int iH;
    private int in;
    private int fin;

    private static int v[] = new int[tam];
    private static int m[][] = new int[tam][tam];
    private static int producto[] = new int[tam];

    /**
     * Constructor
     * @param idHebra identificador de la hebra
     * @param inicio en la division de vector para cada hebra, marca el comienzo del mismo
     * @param finnal en la division de vector para cada hebra, marca el final del mismo
     */

    public matVectorConcurrente(int idHebra, int inicio, int finnal){
        this.iH = idHebra;
        this.in = inicio;
        this.fin = finnal;
    }

    /**
     * Run
     */

    public void run() {
        for (int i = in; i < fin; i++){
            for (int j = 0; j < tam; j++)
                producto[i] = producto[i] + (v[i] * m[i][j]);
        }
    }

    /**
     * Main
     */

    public static void main (String[] args) throws Exception {
        
        int numHebras = 10;
        int desp = 0;

        Random r = new Random();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++)
                m[i][j] = r.nextInt();
            v[i] = r.nextInt();
        }        

        Thread hebras[] = new Thread[numHebras];

        long inicioC = System.currentTimeMillis();         

        for (int i = 0; i < numHebras; i++){
            Runnable aux = new matVectorConcurrente(i, desp, (i + 1) * (tam/numHebras) - 1);
            hebras[i] = new Thread(aux);
            desp = desp + (tam/numHebras);
        }     

        for (int i = 0; i < numHebras; i++) hebras[i].start();
        for (int i = 0; i < numHebras; i++) hebras[i].join();

        long finC = System.currentTimeMillis();

		System.out.println((finC - inicioC) + " ms");
    }
}