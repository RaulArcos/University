/**
 * lectorEscritor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 14/12/2022
 */

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class lectorEscritor {
    public int lectores = 0, escritores = 0;
    public ReentrantLock lock = new ReentrantLock();
    public Condition c = lock.newCondition();

    public synchronized void iniciaLectura()  {
        while (escritores != 0){
            try { c.wait(); } catch (InterruptedException e) {}
        }
        lectores++;
        c.signalAll();
    }

    public synchronized void acabarLectura() {
        lectores--;
        if (lectores == 0)
        c.signalAll();
    }

    public synchronized void iniciarEscritura() {
        while (escritores != 0 || lectores != 0){
            try { c.wait(); } catch (InterruptedException e) {}
        }
        escritores++;
    }

    public synchronized void acabarEscritura() {
        escritores--;
        c.signalAll();
    }
}
