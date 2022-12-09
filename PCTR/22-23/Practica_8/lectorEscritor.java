/**
 * @author Raul Arcos Herrera
 */

public class lectorEscritor {
    private int lectores, escritores;

    public lectorEscritor(){
        lectores = 0;
        escritores = 0;
    }

    public synchronized void empezarLeer() {
        while (escritores != 0)
            try {
                wait();
            } catch (InterruptedException ex) {}
        lectores++;
        notifyAll();
    }

    public synchronized void dejarLeer() {
        lectores--;
        if (lectores == 0)
            notifyAll();
    }

    public synchronized void empezarEscribir() {
        while (escritores != 0 || lectores != 0) {
            try {
                wait();
            } catch (InterruptedException ex) {}
        }
        escritores++;
    }

    public synchronized void dejarEscribir() {
        escritores--;
        notifyAll();
    }
}
