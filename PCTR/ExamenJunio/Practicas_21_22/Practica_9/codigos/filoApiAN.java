/**
 * filoApiAN.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 19/12/2021
 */

import java.util.concurrent.locks.*;

public class filoApiAN {
    public int filosofos;
    public int fork[] = new int[filosofos];
    private ReentrantLock lock = new ReentrantLock();
    public Condition OKtoEat[];

    public filoApiAN (int filosofos, int fork[]){
        this.filosofos = filosofos;
        this.fork = fork;
        this.OKtoEat = new Condition[filosofos];

        for (int i = 0; i < filosofos; i++) OKtoEat[i] = lock.newCondition();
    }

    public void takeForks (int i) throws InterruptedException {
        lock.lock();
        try {
            while (fork[i] != 2) 
                OKtoEat[i].await(); 
        } finally {lock.unlock();}

        if (!sale_del_rango(i, filosofos)) {
            fork [i + 1] = fork [i + 1] - 1;
            fork [i - 1] = fork [i - 1] - 1;
        }
    }

    public void releaseForks (int i) throws InterruptedException{
        lock.lock();
        try {
            if (!sale_del_rango(i, filosofos)) {
                fork [i + 1] = fork [i + 1] + 1;
                fork [i - 1] = fork [i - 1] + 1;
            
                if (fork[i + 1] == 2)
                    OKtoEat[i + 1].signal();
                if (fork[i - 1] == 2)
                    OKtoEat[i - 1].signal();
            }
        } finally {lock.unlock();}
    }

    static boolean sale_del_rango (int i, int filosofos) {
        boolean bool = false;
        if ((i - 1) < 0 || (i + 1) > (filosofos - 1))
            bool = true;
        return bool;
    }
}
