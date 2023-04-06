package ExamenFebrero23;

import java.util.Random;

/**
 * Ejercicio utilizando Thread, multiplicación de matrices utilizando la
 * división en cachitos con thread.
 * 
 * @author Raúl Arcos Herrera
 */

import java.util.random.*;

public class prodMatricesConThread extends Thread {

    public static int n = 12000;
    public static int m1[][] = new int[n][n];
    public static int m2[][] = new int[n][n];

    private static int m[][] = new int[n][n];

    public static int numHilos = 12;
    public static int tamDivision = n / numHilos;

    private int inicio_;
    private int final_;

    /**
     * inicializar.
     * 
     * @param m
     * @param n
     * @return una matriz con valores de 1-10 hasta n.
     */
    public static int[][] inicializar(int[][] m, int n) {
        Random r = new Random();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = r.nextInt(10);
            }
        }
        return m;
    }

    /**
     * prodMatrices, constructor.
     * 
     * @param ini
     * @param fin
     */
    public prodMatricesConThread(int ini, int fin) {
        inicio_ = ini;
        final_ = fin;
    }

    public void run() {
        for (int i = inicio_; i < final_; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = m1[i][j] * m2[i][j];
            }
        }
    }

    public static void main(String[] args) throws Exception {
        m1 = inicializar(m1, n);
        m2 = inicializar(m2, n);

        int[][] m3 = new int[n][n];

        long inicTiempoSec = System.nanoTime();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m3[i][j] = m1[i][j] * m2[i][j];
            }
        }
        long tiempoTotalSec = (System.nanoTime() - inicTiempoSec) / (long) 1.0e6;

        prodMatricesConThread[] vHilos = new prodMatricesConThread[numHilos];
        int seccion = 0;

        for (int i = 0; i < numHilos; i++) {
            vHilos[i] = new prodMatricesConThread(seccion, seccion + tamDivision);
            seccion += tamDivision;
        }

        long inicTiempo = System.nanoTime();
        for (int i = 0; i < numHilos; i++) {
            vHilos[i].start();
        }
        for (int i = 0; i < numHilos; i++) {
            vHilos[i].join();
        }
        long tiempoTotal = (System.nanoTime() - inicTiempo) / (long) 1.0e6;

        System.out.println("Se ha dividido en " + numHilos + " bloque/s de " + tamDivision);
        System.out.println("Calculo secuencial realizado en " + tiempoTotalSec + " Milisegundos");
        System.out.println("Calculo paralelo realizado en " + tiempoTotal + " Milisegundos");
        System.out.println("m[0][0] = " + m[0][0] + " y " + m3[0][0]);
    }
}
