import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.*;
import java.util.*;
import java.util.Vector;
import java.util.Random;
import java.util.Arrays;
import java.util.Scanner;

//----------------------------------JAVA----------------------------------
    //javac programa.java
    //java programa

    import mpi.MPI;

//----------------------------------MPJ----------------------------------
    //COMPILACION: javac -cp .;%MPJ_HOME%/lib/mpj.jar mpj.java
    //COMPILACION MIA: javac -cp C:/Users/Teresa/mpj/lib/mpj.jar mpj.java
    //EJECUCION: mpjrun.bat -np 5 mpj
    //1 master y 4 slave

    import java.util.*;
    import java.net.*;
    import java.rmi.*;

//----------------------------------RMI----------------------------------
    //start rmiregistry
    //java servidor &
    //java cliente

public class utilities {

    Scanner s = new Scanner(System.in);
    Random r = new Random();
    int n_threads = Runtime.getRuntime().availableProcessors(); //hebras de nuestro ordenador
    int tamPool = (int)(n_threads/(float)(1-Cb)); //coeficiente de bloqueo

    int a = s.nextInt();
    int ran = r.nextInt(6); //Numero random entre [0, 6]

    //Imprime un vector entero
    System.out.println (Arrays.toString(x));
    //Duerme los hilos
    Thread.sleep(100);

    //FUNCIONES LAMBDA
        Runnable r1 = () -> { for(int i = 0; i < 10000; ++i) /*SC*/; };
        Runnable r2 = () -> { for(int i = 0; i < 10000; ++i) /*SC*/; };

    //TIEMPOS
        //ns
            long iniTime = System.nanoTime();

            long finTime = System.nanoTime() - iniTime;
        //ms
            long tIni = System.currentTimeMillis();
            
            long tPar = System.currentTimeMillis() - tIni;
        //SpeedUP
            System.out.println ("SpeedUp: " + ((double)(tSec/tPar) / 1000)); //tiempo en MS
            System.out.println ("SpeedUP: " + ((double)((fTimeSec/ 1e9) / (fTimePar/ 1e9))));  //tiempo en NS
}
