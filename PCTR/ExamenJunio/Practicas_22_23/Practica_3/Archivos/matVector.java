/**
 * prodEscalar.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 26/10/2022
 */

import java.util.*;

public class matVector {

    /**
     * Main
     */
     
    public static void main (String[] args) {
        int tam = (int)Math.pow(10, 4);

        int m[][] = new int[tam][tam];
        int v[] = new int[tam];
        int producto[] = new int[tam];

        Random r = new Random();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++)
                m[i][j] = r.nextInt();
            v[i] = r.nextInt();
        }

        long iniciaC = System.currentTimeMillis();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++)
                producto[i] = producto[i] + (v[i] * m[i][j]);
        }

        long finC = System.currentTimeMillis();
        System.out.println((finC - iniciaC) + " ms");
    }

}