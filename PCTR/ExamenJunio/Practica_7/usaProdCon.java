/**
 * usaProdCon.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 2/12/2021
 */

import java.lang.Exception;

public class usaProdCon extends Thread {
  public int tipoHebra;
  public ProdCon pc;
  public static int temp = 0;

  public usaProdCon(int tH, ProdCon pc) {
      this.tipoHebra = tH;
      this.pc = pc;
  }

  public void run (){
      switch (tipoHebra){
          case 0:
              pc.Append(10000);
          break;
          case 1:
              pc.Take();
          break;
      }
  }

  public static void main (String[] args) throws Exception{
      ProdCon pc = new ProdCon();

      Thread h1 = new Thread (new usaProdCon(1, pc));
      Thread h2 = new Thread (new usaProdCon(0, pc));
      Thread h3 = new Thread (new usaProdCon(0, pc));

      h1.start(); h2.start(); h3.start();
      h1.join(); h2.join(); h3.join();
  }
}

class ProdCon {
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
