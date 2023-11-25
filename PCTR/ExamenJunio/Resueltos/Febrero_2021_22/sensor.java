import java.util.concurrent.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

public class sensor extends Thread {
    public static int[] senalEntradaZeta, senalEntradaRho, senalSalidaXi;
    private static int start, end;
    public static int n;

    public sensor (int s, int e) {
        start = s;
        end = e;
    }

    public synchronized void run (){
        for (int i = start; i < end; i++) {
            if (i - 1 < 0) {
                senalSalidaXi[i] = (senalEntradaZeta[i] + senalEntradaZeta[i + 1]) + (senalEntradaRho[i] + 0);
            } else if (i + 1 >= n) {
                senalSalidaXi[i] = (senalEntradaZeta[i] + 0) + (senalEntradaRho[i] + senalEntradaRho[i - 1]);
            } else {
                senalSalidaXi[i] = (senalEntradaZeta[i] + senalEntradaZeta[i + 1]) + (senalEntradaRho[i] + senalEntradaRho[i - 1]);
            }
        }
    }
    public static void main (String[] args) throws Exception{
        Scanner s = new Scanner(System.in);
        Random r = new Random();
        System.out.println ("Eliga una opcion:\n [1] Manual\n [2] Automatico");
        int op = s.nextInt(), i = 0, numHebras = 0;
        long iniTimePar, iniTimeSec, k = 0, p = 0;

        switch(op) {
            case 1: 
                System.out.println("Introduzca tamaño de los datos de las señales:");
                n = s.nextInt();
                senalEntradaZeta  = new int[n];
                senalEntradaRho = new int[n];
                senalSalidaXi = new int[n];

                for (i = 0; i < n; i++) {
                    do {
                        System.out.println("Introduzca el dato " + i + " comprendido entre [0, 4] para la Señal de Zeta: ");
                        senalEntradaZeta[i] = s.nextInt();
                    } while (senalEntradaZeta[i] < 0 || senalEntradaZeta[i] > 4);
                }

                for (i = 0; i < n; i++) {
                    do {
                        System.out.println("Introduzca el dato " + i + " comprendido entre [0, 4]  para la Señal de Rho: ");
                        senalEntradaRho[i] = s.nextInt();
                    } while (senalEntradaRho[i] < 0 || senalEntradaRho[i] > 4);
                }

                System.out.println("Introduzca el numero de hebras:");
                numHebras = s.nextInt();
            break;

            case 2:
                n = (int)10e7;
                numHebras = Runtime.getRuntime().availableProcessors();
                senalEntradaZeta  = new int[n];
                senalEntradaRho = new int[n];
                senalSalidaXi = new int[n];

                for (i = 0; i < n; i++) {
                    senalEntradaZeta[i] = r.nextInt(5);
                    senalEntradaRho[i] = r.nextInt(5);
                }

                ThreadPoolExecutor eptSec = (ThreadPoolExecutor)Executors.newFixedThreadPool(1);
                iniTimeSec = System.nanoTime();

                eptSec.execute(new sensor(0, n));

                eptSec.shutdown();
                while(!eptSec.isShutdown()) eptSec.awaitTermination(10, TimeUnit.SECONDS);

                k = System.nanoTime() - iniTimeSec;
            break;

            default:
                System.out.println ("Opcion incorrecta");
        }

        int start = 0, desp = n / numHebras, end = desp; 
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(numHebras);

        iniTimePar = System.nanoTime();
        for (i = 0; i < numHebras; i++) {
            ept.execute(new sensor(start, end));
            Thread.sleep(10);
            start = end;
            end = end + desp;
        }

        ept.shutdown();
        while(!ept.isShutdown()) ept.awaitTermination(10, TimeUnit.SECONDS);

        p = System.nanoTime() - iniTimePar - (long)10e6*numHebras;

        if (op == 1) {
            System.out.println ("Señal original de Zeta: " + Arrays.toString(senalEntradaZeta));
            System.out.println ("Señal original de Rho: " + Arrays.toString(senalEntradaRho));
            System.out.println ("Señal transformada: " + Arrays.toString(senalSalidaXi));
        } else {
            System.out.println ("Tiempo  de ejecucion secuencial: " + k + " nanosegundos");
            System.out.println ("Tiempo  de ejecucion paralelo: " + p + " nanosegundos");
        }
    }
}
