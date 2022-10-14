/**
 * prodEscalar.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 05/11/2021
 */

import java.util.*;

public class prodEscalarParalelo extends Thread {

    static int tam = (int)Math.pow(10,6);
    private int iH;
    private int in;
    private int fin;

    private static int v1[] = new int[tam];
    private static int v2[] = new int[tam];
    private static int productoParcial[];

    /**
     * Constructor
     * @param idHebra identificador de la hebra
     * @param inicio en la division de vector para cada hebra, marca el comienzo del mismo
     * @param finnal en la division de vector para cada hebra, marca el final del mismo
     */

    public prodEscalarParalelo(int idHebra, int inicio, int finnal){
        this.iH = idHebra;
        this.in = inicio;
        this.fin = finnal;
    }

    /**
     * Run
     */

    public void run() {
        for (int i = in; i < fin + 1; i++)
            productoParcial[iH] = productoParcial[iH] + (v1[i] * v2[i]);
    }

    /**
     * Main
     */
     
    public static void main (String[] args) throws Exception {

        int numHebras = 10;
        int productoEscalar = 0;
        int desp = 0;

        for (int i = 0; i < tam; i++){
            v1[i] = i;
            v2[i] = i;
        } 

        productoParcial = new int[numHebras];

        prodEscalarParalelo hebras[] = new prodEscalarParalelo[numHebras];

        long inicioC = System.currentTimeMillis();         

        for (int i = 0; i < numHebras; i++){
            hebras[i] = new prodEscalarParalelo(i, desp, (i + 1) * (tam/numHebras) - 1);
            desp = desp + (tam/numHebras);
        }

        for (int i = 0; i < numHebras; i++) hebras[i].start();
        for (int i = 0; i < numHebras; i++) hebras[i].join();

        long finC = System.currentTimeMillis();
        
        for(int i = 0; i < numHebras; i++) 
            productoEscalar = productoEscalar + productoParcial[i];

		System.out.println((finC - inicioC) + " ms");
    }
}