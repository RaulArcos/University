/**
 * usaprodCon.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2022
 */

import java.lang.Exception;

public class usaprodCon extends Thread {
  public int tipoHebra;
  public prodCon pc;
  public static int temp = 0;

  public usaprodCon(int tH, prodCon pc) {
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
      prodCon pc = new prodCon();

      Thread h1 = new Thread (new usaprodCon(1, pc));
      Thread h2 = new Thread (new usaprodCon(0, pc));
      Thread h3 = new Thread (new usaprodCon(0, pc));

      h1.start(); h2.start(); h3.start();
      h1.join(); h2.join(); h3.join();
  }
}
