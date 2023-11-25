/**
 * recurso.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 30/11/2022
 */

public class recurso {
    public static long n = 0;

    public synchronized void inc () {n++;}
    public long observer () {return n;}
}
