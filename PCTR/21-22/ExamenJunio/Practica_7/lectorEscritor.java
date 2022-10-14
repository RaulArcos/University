/**
 * lectorEscritor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 2/12/2021
 */

public class lectorEscritor {
    public int readers = 0, writers = 0;

    public synchronized void StartRead() {
        while (writers != 0){
            try { wait(); } catch (InterruptedException e) {}
        }
        readers++;
        System.out.println("Escritores a 0, toca el turno a los lectores");
        notifyAll();
    }

    public synchronized void EndRead() {
        readers--;
        System.out.println("Lectores a 0, se acabo leer");
        if (readers == 0)
            notifyAll();
    }

    public synchronized void StartWrite() {
        while (writers != 0 || readers != 0){
            try { wait(); } catch (InterruptedException e) {}
        }
        writers++;
        System.out.println("Existen escritores y lectores");
    }

    public synchronized void EndWrite() {
        writers--;
        System.out.println("Escritores a 0, se acabo escribir");
        notifyAll();
    }
}
