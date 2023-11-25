/**
 * cCRL.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 14/12/2022
 */

import java.util.concurrent.locks.ReentrantLock;

public class cCRL {
    private int id;
    private double saldo;
    public ReentrantLock lock = new ReentrantLock();
    
    public cCRL (int i, double s) {
        this.id = i;
        this.saldo = s;
    }

    public int id() {return id;}
    public double saldo () {return saldo;}

    public double ingresar (double n) { 
        lock.lock();
        try {
            return this.saldo + n;
        } finally {lock.unlock();}
    }

    public double retirar (double n) { 
        lock.lock();
        try {
            return this.saldo - n;
        } finally {lock.unlock();}
    }
}