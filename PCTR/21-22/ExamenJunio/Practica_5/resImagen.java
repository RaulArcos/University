/**
 * resImagen.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 18/11/2021
 */

import java.util.*;
import java.util.concurrent.*;

public class resImagen {
    public static void main (String[] args) throws Exception{
        int tam = 10000;
        int m[][] = new int[tam][tam];

        Random r = new Random();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++)
                m[i][j] = r.nextInt() % 255;
        }

        long iniciaC = System.nanoTime();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++){
                m[i][j] = m[i][j] * 4;

                if (i - 1 >= 0) m[i][j] = m[i][j] - m[i - 1][j];
                if (i + 1 < tam) m[i][j] = m[i][j] - m[i + 1][j];                
                if (j - 1 >= 0) m[i][j] = m[i][j] - m[i][j - 1];
                if (j + 1 < tam) m[i][j] = m[i][j] - m[i][j + 1];

                m[i][j] = m[i][j] / 8;
            }
        }

        System.out.println(((System.nanoTime() - iniciaC)/(long)1.0e9) + " s");
    }
}
