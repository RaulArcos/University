/**
 * prodMatricesSecuencial.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 09/11/2022
 */


public class prodMatricesSecuencial {
    public static void main (String[] arg) {

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

        long iniciaC = System.nanoTime();

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++){
                res = 0;
                for (int k = 0; k < tam; k++)
                    res = res + (m1[j][k] * m2[k][i]);
                m[j][i] = res;
            }
        }

        System.out.println(((System.nanoTime() - iniciaC)/(long)1.0e9) + " s");
    }
}
