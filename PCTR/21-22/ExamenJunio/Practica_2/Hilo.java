/*
 COMPARTIENDO MEMORIA ENTRE HEBRAS: VARIBLES DE CLASE 
*/
public class Hilo 
  extends Thread 
{ 
    private int tipoHilo; 
    private static int n=0; //variable de clase 
    private int nVueltas; 
 
    public Hilo(int nVueltas, int tipoHilo) 
    {this.nVueltas=nVueltas; this.tipoHilo=tipoHilo;} 
 
    public void run() 
    { 
      switch(tipoHilo){ 
        case 0: for(int i=0; i<nVueltas; i++)n++; break; 
        case 1: for(int i=0; i<nVueltas; i++)n--; break; 
      } 
 
    } 
 
  public static void main(String[] args) 
      throws Exception 
  { 
      Hilo p = new Hilo(10000, 0); 
      Hilo q = new Hilo(10000, 1); 
      p.start(); 
      q.start(); 
      p.join(); 
      q.join(); 
      System.out.println(n); 
  } 
 
}