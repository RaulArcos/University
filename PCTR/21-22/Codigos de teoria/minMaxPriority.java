public class minMaxPriority extends Thread{
  public void run(){
    for(int i=0; i<100; i++)
      System.out.println("Hebra "+this.getName());
  }
  public static void main(String[] args){
    minMaxPriority p = new minMaxPriority();
    minMaxPriority q = new minMaxPriority();
    p.setName("Baja...");
    q.setName("Alta...");
    p.setPriority(Thread.MIN_PRIORITY);
    q.setPriority(Thread.MAX_PRIORITY);
    p.start(); q.start();
  }
}
