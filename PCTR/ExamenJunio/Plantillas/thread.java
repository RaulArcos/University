import java.util.concurrent.ThreadPoolExecutor;

public class thread extends Thread { 
    private static int n = 0; //Variable compartida - SC
 
    //Constructor
    public thread() {} 
 
    public void run() { 
        //Protocolo de exclusion mutua y SC
    } 
 
    public static void main(String[] args) throws Exception { 
            //Hilos
                thread p = new thread(); //Creamos hilos
                p.start(); p.join(); //start (prepara los hilos para lanzarlos) y join (espera que el hilo termine la ejecucion)

            //Vector de hilos con herencia de Thread
                int numHebras = 2;
                Thread hebras[] = new Thread[numHebras]; //creamos el vector
                for (int i = 0; i < numHebras; i++) hebras[i] = new Thread(new thread()); //rellenamos el vector con el constructor de la clase
                for (int i = 0; i < numHebras; i++) hebras[i].start();
                for (int i = 0; i < numHebras; i++) hebras[i].join();

            //Vector de hilos con implementse Runnable
                Thread hebras[] = new Thread[numHebras];
                for (int i = 0; i < numHebras; i++){
                    Runnable aux = new thread();
                    hebras[i] = new Thread(aux);
                }  
                for (int i = 0; i < numHebras; i++) hebras[i].start();
                for (int i = 0; i < numHebras; i++) hebras[i].join();

    } 

    //Pool de threads: public ThreadPoolExecutor(int corePoolSize, int maximumPoolsize, long keepAliveTime,TimeUnit unit, BlockingQueue<Runnable>workQueue)
    //min nº de hilos, max nº de hilos, tiempo de vida de los hilos, unidad de tiempo, lista de trabajo)
        ThreadPoolExecutor ept = new ThreadPoolExecutor(numHebras, numHebras, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());
    //MAS UTIL
        ThreadPoolExecutor ept = (ThreadPoolExecutor)Executors.newFixedThreadPool(numHebras);
}
