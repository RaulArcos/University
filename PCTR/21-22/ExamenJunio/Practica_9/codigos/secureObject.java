import java.util.concurrent.locks.*;

public class secureObject{
  public long      n = 0;
  public ReentrantLock lock = new ReentrantLock();
  
  public secureObject(){}

  public void inc(){
    lock.lock();
    try{n++;}
    finally{lock.unlock();}
  }

  public long get(){
    lock.lock();
    try{return this.n;}
    finally{lock.unlock();}  
  }
}

