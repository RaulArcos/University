
/**
 * @author Raúl Arcos Herrera
 * 
*/
public class deadlock extends Thread
{

  private Object  A_;
  private Object  B_; 
  private int n_ = 0;

  public deadlock(Object a, Object b)
  {
    A_ = a;
    B_ = b;
  }

  public void run()
  {
    synchronized(A_) 
    {
      for(int i=0; i<100000;i++);
      synchronized(B_)
      {
        System.out.println(n_);
      }
    }
  }

  public static void main(String[] args) throws Exception
  {
    
    Object  a = new Object();
    Object  b = new Object();
    Object  c = new Object();

    Thread Hilo_A = new Thread(new deadlock(a, b));
    Thread Hilo_B = new Thread(new deadlock(b, c));
    Thread Hilo_C = new Thread(new deadlock(c, a));

    Hilo_C.start();Hilo_B.start();Hilo_A.start();
    Hilo_C.join();Hilo_B.join();Hilo_A.join();
  
  }
}