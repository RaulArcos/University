import java.util.concurrent.*;

public class waveEq2D implements Runnable {
    private static int start, end;

    public waveEq2D(int s, int e) {
        start = s;
        end = e;
    }

    // IMPORTANTE PORQUE ES RUNNABLE, se necesita metodo run
    public void run() {
        // funcion que hace cosas (TENER EN CUENTA LAS FRONTERAS)
        for (int i = start; i < end; i++) {
            // hace cosas
        }
    }

    public static void main(String[] args) throws Exception {
        int numHebras = Runtime.getRuntime().availableProcessors(); // Las hebras de nuestro ordenador

        // ThreadPool
        ThreadPoolExecutor ept = (ThreadPoolExecutor) Executors.newFixedThreadPool(numHebras);

        // Pedir datos

        // Opciones (manual/automatico seguramente)
        switch (op) {
            case 1:

                break;

            case 2:

                break;

            default:
                System.out.println("Opcion incorrecta");
        }

        // Division de los datos
        int start = 0, desp = n / numHebras, end = desp;

        for (int i = 0; i < numHebras; i++) {
            ept.execute(new divRunnable(start, end));
            Thread.sleep(100);
            start = end;
            end = end + desp;
        }

        ept.shutdown();
        while (!ept.isShutdown())
            ept.awaitTermination(10, TimeUnit.SECONDS);
    }
}
