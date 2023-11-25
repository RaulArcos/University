/**
 * ccSem.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 14/12/2022
 */

import java.util.concurrent.Semaphore;

public class ccSem {
    private int id;
    private double saldo;
    public Semaphore sem = new Semaphore(1);
    
    public ccSem (int i, double s) {
        this.id = i;
        this.saldo = s;
    }

    public int id() {return id;}
    public double saldo () {return saldo;}

    public double ingresar (double n) { 
        try {
            return this.saldo + n;
        } finally {sem.release();}
    }

    public double retirar (double n) { 
        try {
            return this.saldo - n;
        } finally {sem.release();}
    }
}
