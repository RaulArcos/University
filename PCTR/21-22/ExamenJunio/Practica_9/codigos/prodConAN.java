/**
 * prodConAN.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 19/12/2021
 */

import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.*;

public class prodConAN {
    public final int N = 100;
    public int Oldest = 0, Newest = 0;
    public volatile int Count = 0;
    public int Buffer[] = new int[N];
    public static ReentrantLock lock = new ReentrantLock();
    public Condition notFull = lock.newCondition();
    public Condition notEmpty = lock.newCondition();

    public prodConAN(){}

    public void Append(int V) throws InterruptedException {
        lock.lock();
        try {
            while (Count == N)
                notFull.await();
            Buffer[Newest] = V;
            Newest = (Newest + 1) % N;
            Count = Count + 1;
            notEmpty.signalAll();
        } finally {lock.unlock();}
    }            

    public int Take() throws InterruptedException {
        int temp;
        lock.lock();
        try {
            while (Count == 0)
                notEmpty.await();
            temp = Buffer[Oldest];
            Oldest = (Oldest + 1) % N;
            Count = Count - 1;
            notFull.signalAll();
            return temp;
        } finally {lock.unlock();}
    }
}
