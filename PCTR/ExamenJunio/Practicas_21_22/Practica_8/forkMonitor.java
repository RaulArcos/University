/**
 * forkMonitor.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 4/12/2021
 */

public class forkMonitor {
    public int filosofos;
    public int fork[] = new int[filosofos];

    public forkMonitor (int filosofos, int fork[]){
        this.filosofos = filosofos;
        this.fork = fork;
    }

    public synchronized void takeForks (int i) {
        while (fork[i] != 2) {try { wait(); } catch (InterruptedException e) {} }

        if (!sale_del_rango(i, filosofos)) {
            fork [i + 1] = fork [i + 1] - 1;
            fork [i - 1] = fork [i - 1] - 1;
        }
    }

    public synchronized void releaseForks (int i) {
        if (!sale_del_rango(i, filosofos)) {
            fork [i + 1] = fork [i + 1] + 1;
            fork [i - 1] = fork [i - 1] + 1;
        
        if (fork[i + 1] == 2 || fork[i - 1] == 2)
            notifyAll();
        }
    }

    static boolean sale_del_rango (int i, int filosofos) {
        boolean bool = false;
        if ((i - 1) < 0 || (i + 1) > (filosofos - 1))
            bool = true;
        return bool;
    }
}
