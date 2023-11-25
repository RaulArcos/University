import java.util.concurrent.*;
import java.util.Scanner;
import java.util.Random;

public class waveEq2D implements Runnable{
    public static int n, m, t;
    private final int start, end;
    private static float c = 1/4;
    public static int[][] A;
    private static boolean manual = false;

    public waveEq2D (int s, int e) {
        start = s;
        end = e;
    }

    public static void set_t (int t_) {t = t_;}

    public static synchronized void imprimir_estado (int i_t) {
        System.out.println("Periodo: " + i_t + " en el hilo: " + Thread.currentThread() + "\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("\n");
    }
    
    public void run () {
        for (int i_t = 0; i_t < t; i_t++) {
            for (int i = start; i < end; i++) {
                for (int j = 0; j < m; j++) { //n x m
                    if (i - 1 < 0 && j - 1 >= 0 && j + 1 < m) {
                        A[i][j] = Math.round((c*c) * (A[i+1][j] + 0 + A[i][j+1] + A[i][j-1] - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i - 1 < 0 && j - 1 < 0) {
                        A[i][j] = Math.round((c*c) * (A[i+1][j] + 0 + A[i][j+1] + 0 - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i - 1 < 0 && j + 1 >= m) {
                        A[i][j] = Math.round((c*c) * (A[i+1][j] + 0 + 0 + A[i][j-1] - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i + 1 >= n && j - 1 >= 0 && j + 1 < m) {
                        A[i][j] = Math.round((c*c) * (0 + A[i-1][j] + A[i][j+1] + A[i][j-1] - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i + 1 >= n && j - 1 < 0) {
                        A[i][j] = Math.round((c*c) * (0 + A[i-1][j] + A[i][j+1] + 0 - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i + 1 >= n && j + 1 >= m) {
                        A[i][j] = Math.round((c*c) * (0 + A[i-1][j] + 0 + A[i][j-1] - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i - 1 >= 0 && i + 1 < n && j - 1 < 0) {
                        A[i][j] = Math.round((c*c) * (A[i+1][j] + A[i-1][j] + A[i][j+1] + 0 - 4 * A[i][j]) + (2 * A[i][j]));
                    } else if (i - 1 >= 0 && i < n && j + 1 >= m) {
                        A[i][j] = Math.round((c*c) * (A[i+1][j] + A[i-1][j] + 0 + A[i][j-1] - 4 * A[i][j]) + (2 * A[i][j]));
                    } else {
                        A[i][j] = Math.round((c*c) * (A[i+1][j] + A[i-1][j] + A[i][j+1] + A[i][j-1] - 4 * A[i][j]) + (2 * A[i][j]));
                    }
                }
            }
            if (manual) imprimir_estado(i_t);
        }
    }

    public static void main (String[] args) throws Exception{
        Scanner s = new Scanner(System.in);
        Random r = new Random();
        double Cb = 0.0;
        long tSec = 0;
        int n_threads = Runtime.getRuntime().availableProcessors();
        int tamPool = (int)(n_threads/(float)(1-Cb));
        ThreadPoolExecutor ept =(ThreadPoolExecutor)Executors.newFixedThreadPool(tamPool);

        System.out.println ("Eliga una opcion:\n [1] Cargar reticula con datos aleatorios\n [2] Cargar reticula con datos concretos introducidos por teclado");
        int op = s.nextInt();
        System.out.println ("Introduzca el periodo: ");
        set_t(s.nextInt());

        switch(op) {
            case 1: 
                n = 1000;
                m = 1000;
                A = new int[n][m];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++)
                        A[i][j] = r.nextInt(100) - r.nextInt(100);
                }
                long tIniPar = System.currentTimeMillis();
                Thread h = new Thread (new waveEq2D (0, n));
                h.run(); h.join();
                tSec = System.currentTimeMillis() - tIniPar;
            break;

            case 2:
                manual = true;
                System.out.println("Introduzca el numero de filas:");
                n = s.nextInt();
                System.out.println("Introduzca el numero de columnas:");
                m = s.nextInt();
                A = new int[n][m];

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++){
                        System.out.println("Introduzca el dato " + i + ", " + j + ": ");
                        A[i][j] = s.nextInt();
                    }
                }
            break;

            default:
                System.out.println ("Opcion incorrecta");
        }

        int start = 0, desp = n / n_threads, end = desp; 
        long tIni = System.currentTimeMillis();
        
        for (int i = 0; i < n_threads; i++) {
            ept.execute(new waveEq2D(start, end));
            Thread.sleep(10);
            start = end;
            end = end + desp;
        }

        ept.shutdown();

        while(!ept.isShutdown()) ept.awaitTermination(10, TimeUnit.SECONDS);
        
        long tPar = System.currentTimeMillis() - tIni;

        if (op == 1) {
            System.out.println ("SpeedUp: " + ((double)(tSec/tPar) / 1000));
        }

        s.close();
    }
}