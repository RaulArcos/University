import java.util.concurrent.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.*;

public class Convol implements Runnable {
    private int start, end;
    public static int n;
    public static int k0, k1, k2;
    public static int[] x, y;

    public Convol (int s, int e, int[] v1, int[] v2) {
        start = s;
        end = e;
        x = v1;
        y = v2;
    }  

    //Rellenar el vector automático
    public static void rellenarVector (int[] v) {
        Random r = new Random();
        for (int i = 0; i < v.length; i++) {
            v[i] = r.nextInt(11) - 5;
        }
    }
    //IMPORTANTE PORQUE ES RUNNABLE, se necesita metodo run
    public void run(){
        //funcion que hace cosas (TENER EN CUENTA LAS FRONTERAS)
            for (int i = start; i < end; i++) {
                if(i == 0){
                    y[i] = ((k0 * x[n-1]) + (k1 * x[i]) + (k2 * x[i+1]));
                }else if(i == n-1){
                    y[i] = ((k0 * x[i-1]) + (k1 * x[i]) + (k2 * x[0]));
                }else{
                    y[i] = ((k0 * x[i-1]) + (k1 * x[i]) + (k2 * x[i+1]));
                }
            }
    }

    public static void main (String[] args) throws Exception{
        int numHebras = 8; //Las hebras de nuestro ordenador
        
        //ThreadPool
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(numHebras);

        //Pedir datos
        System.out.println("Introduzca los valores de k0, k1 y k2 [-1,1]: ");
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("Introduzca el valor de k0: ");
            k0 = sc.nextInt();
        }while(k0 < -1 || k0 > 1);

        do{
            System.out.println("Introduzca el valor de k1: ");
            k1 = sc.nextInt();
        }while(k1 < -1 || k1 > 1);

        do{
            System.out.println("Introduzca el valor de k2: ");
            k2 = sc.nextInt();
        }while(k2 < -1 || k2 > 1);
   
        int op = 0;
        while(op != 1 && op != 2){
        System.out.println("Seleccione el modo de 1DConvol:\n[1] Automatico\n[2] Manual\n");
        op = sc.nextInt();
        }

        //Opciones (manual/automatico seguramente)
        switch(op) {
            case 1: 
                n = 1000;
                x = new int [n];
                y = new int [n];
                rellenarVector(x);
            break;
            case 2:
                System.out.println("Introduzca el tamaño del vector debe ser par: ");
                n = sc.nextInt();
                x = new int [n];
                y = new int [n];
                System.out.println("Introduzca los valores del vector [-5,5]: ");
                for (int i = 0; i < x.length; i++) {
                    do{
                        System.out.print("[" + i + "]:");
                        x[i] = sc.nextInt();
                    }while(x[i] < -5 || x[i] > 5);
                }
            break;

            default:
                System.out.println ("Opcion incorrecta");
        }

        //Division de los datos
        if(n < numHebras){
            numHebras = n;
        }
        int start = 0, desp = n / numHebras, end = desp, end_aux = 0;
        double startTime = System.nanoTime();

        for (int i = 0; i < numHebras; i++) {
            ept.execute(new Convol(start, end, x, y));
            start = end;
            end = end + desp;
        }
        
        ept.shutdown();
        try{
            ept.awaitTermination(10, TimeUnit.SECONDS);
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        double endTime = System.nanoTime();

        switch(op) {
            case 1: 
                System.out.println("Tiempo total de ejecución: " + (endTime - startTime) + " ns");
            break;
            case 2:
                System.out.println("Señal original: " + Arrays.toString(x) + "\nSeñal convolucionada: " + Arrays.toString(y));
            break;

            default:
                System.out.println ("Opcion incorrecta");
        }
    }
}