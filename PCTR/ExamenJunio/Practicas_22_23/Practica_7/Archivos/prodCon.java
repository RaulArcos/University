/**
 * prodCon.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2022
 */


class prodCon {
    public final int N = 100;
    public int Oldest = 0, Newest = 0;
    public volatile int Count = 0;
    public int Buffer[] = new int[N];
  
    public synchronized void Append(int V) {
      while (Count == N)
        try {
          wait();
        } catch (InterruptedException e) {}
      Buffer[Newest] = V;
      Newest = (Newest + 1) % N;
      Count = Count + 1;
      System.out.println("Se termino de rellenar, toca coger");
      notifyAll();
    }
  
    public synchronized int Take() {
      int temp;
      while (Count == 0)
        try {
          wait();
        } catch (InterruptedException e) {}
      temp = Buffer[Oldest];
      Oldest = (Oldest + 1) % N;
      Count = Count - 1;
      System.out.println("Se ha vaciado, toca rellenar");
      notifyAll();
      return temp;
    }
}