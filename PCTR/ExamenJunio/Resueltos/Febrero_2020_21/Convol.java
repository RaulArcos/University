import java.util.concurrent.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

public class Convol implements Runnable {
    public static int k_0 = 0,  k_1 = 0, k_2 = 0, n;
    public static int x[] , y[];
    private static int start, end;

    public Convol (int s, int e) {
        start = s;
        end = e;
    }

    public synchronized void run(){
        for (int i = start; i < end; i++) {
            if ((i - 1) < 0) {
                y[i] = ((x[n - 1] * k_0) + (x[i] * k_1) + (x[i + 1] * k_2));
            } else if ((i + 1) >= n) {
                y[i] = ((x[i - 1] * k_0) + (x[i] * k_1) + (x[0] * k_2));
            } else {
                y[i] = ((x[i - 1] * k_0) + (x[i] * k_1) + (x[i + 1] * k_2));
            }
        }
    }

    public static void main (String[] args) throws Exception{
        Scanner s = new Scanner(System.in);
        Random r = new Random();
        int numHebras = 8;
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(numHebras);
        do {
            System.out.println ("Introduzca un valor k_0 entero comprendido entre [-1, 1]: ");
            k_0 = s.nextInt();
        } while (k_0 != 0 && k_0 != 1 && k_0 != -1);

        do {
            System.out.println ("Introduzca un valor k_1 entero comprendido entre [-1, 1]: ");
            k_1 = s.nextInt();
        } while (k_1 != 0 && k_1 != 1 && k_1 != -1);

        do {
            System.out.println ("Introduzca un valor k_2 entero comprendido entre [-1, 1]: ");
            k_2 = s.nextInt();
        } while (k_2 != 0 && k_2 != 1 && k_2 != -1);

        System.out.println ("Eliga una opcion:\n [1] Automatico\n [2] Manual");
        int op = s.nextInt();

        switch(op) {
            case 1: 
                n = 10000;
                x = new int[n];
                y = new int[n];
                for (int i = 0; i < n; i++) {
                    x[i] = r.nextInt(5) - r.nextInt(5);
                }
            break;

            case 2:
                System.out.println("Introduzca tamaño de la señal original:");
                n = s.nextInt();
                x = new int[n];
                y = new int[n];

                for (int i = 0; i < n; i++) {
                    do {
                        System.out.println("Introduzca el dato " + i + " comprendido entre [5, -5]: ");
                        x[i] = s.nextInt();
                    } while (x[i] < -5 || x[i] > 5);
                }
                System.out.println ("Señal original: ");
                System.out.println (Arrays.toString(x));
            break;

            default:
                System.out.println ("Opcion incorrecta");
        }

        int start = 0, desp = n / numHebras, end = desp; 
        long iniTime = System.nanoTime();

        for (int i = 0; i < numHebras; i++) {
            ept.execute(new Convol(start, end));
            Thread.sleep(100);
            start = end;
            end = end + desp;
        }

        ept.shutdown();
        while(!ept.isShutdown()) ept.awaitTermination(10, TimeUnit.SECONDS);

        long finTime = System.nanoTime() - iniTime;

        if(op == 1) {
            System.out.println ("Tiempo de ejecución paralelo: " + finTime + " ns.");
        } else {
            System.out.println ("Señal convoluta: ");
            System.out.println (Arrays.toString(y));
        }
    }
}
