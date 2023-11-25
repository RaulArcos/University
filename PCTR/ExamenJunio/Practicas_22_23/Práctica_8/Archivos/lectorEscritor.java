/**
 * lectorEscritor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 30/11/2022
 */

public class lectorEscritor {
    public int lectores = 0, escritores = 0;

    public synchronized void iniciaLectura() {
        while (escritores != 0){
            try { wait(); } catch (InterruptedException e) {}
        }
        lectores++;
        notifyAll();
    }

    public synchronized void acabarLectura() {
        lectores--;
        if (lectores == 0)
            notifyAll();
    }

    public synchronized void iniciarEscritura() {
        while (escritores != 0 || lectores != 0){
            try { wait(); } catch (InterruptedException e) {}
        }
        escritores++;
    }

    public synchronized void acabarEscritura() {
        escritores--;
        notifyAll();
    }
}
