import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class prodConAN {
  
  public final int N = 10;
  public int Oldest = 0, Newest = 0;
  public int Count = 0;
  public int Buffer[] = new int[N];
  final ReentrantLock lock = new ReentrantLock();
  final Condition  notEmpty = lock.newCondition();
  final Condition  notFull = lock.newCondition();

  public void Append(int V)throws InterruptedException {
    lock.lock();
      try {
       
        while (Count == N)
            notFull.await();
        
        Buffer[Newest] = V;
        Newest = (Newest + 1) % N;
        Count = Count + 1;
        notEmpty.signal();

      } finally{lock.unlock();}
	}

  public int Take()throws InterruptedException {
    lock.lock();
    int temp;
    try 
    { 
        while (Count == 0)
            notEmpty.await();
   
        temp = Buffer[Oldest];
		Oldest = (Oldest + 1) % N;
		Count = Count - 1;
        notFull.signal();
        return temp;

    }finally{lock.unlock();}
    }
}
