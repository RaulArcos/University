/**
 * heterogenea.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 15/11/2022
 */

public class heterogenea {
    public static int n = 0;
    public static int m = 0;

    public synchronized void incs(){n++;}
    public void inc(){m++;}

    public int m() {return m;}
    public int n() {return n;}
}
