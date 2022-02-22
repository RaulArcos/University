/**
 * @author Raul Arcos Herrera
 */

public class usaLectorEscritor extends Thread 
{

    lectorEscritor le = new lectorEscritor();
    boolean escritor;

    public usaLectorEscritor(lectorEscritor m, boolean escritor) {
        this.le = m;
        this.escritor = escritor;
    }

    public void run() {
        while (true) {
            if (escritor) {
                le.empezarEscribir();
                System.out.println("Thread " + Thread.currentThread().getName() + " Empieza a Escribir.");
                le.dejarEscribir();
            } else {
                le.empezarLeer();
                System.out.println("Thread " + Thread.currentThread().getName() + " Empieza a leer.");
                le.dejarLeer();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        
        lectorEscritor m = new lectorEscritor();
        usaLectorEscritor A = new usaLectorEscritor(m, true);
        usaLectorEscritor B = new usaLectorEscritor(m, true);
        usaLectorEscritor C = new usaLectorEscritor(m, false);

        A.start();  A.join();
        B.start();  B.join();
        C.start();  C.join();
    }
}
