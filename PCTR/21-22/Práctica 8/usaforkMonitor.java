/**
 * @author Raúl Arcos Herrera
 */
public class usaforkMonitor extends Thread
{
    public forkMonitor forkm;
    public int filosofo=0;
    public usaforkMonitor(forkMonitor forkMonitor){this.forkm = forkMonitor;}

    public void run(){
       
        for(int i=0; i<100; i++)
        {
            if(filosofo > 4)
                filosofo = 0;
            System.out.println("El filosofo "+ filosofo +" PIENSA.");
            forkm.takeForks(filosofo);
            System.out.println("El filosofo "+ filosofo +" COME.");
            forkm.releaseForks(filosofo);
            filosofo++;
        }
    }

    public static void main(String[] args) throws Exception{
        forkMonitor forkm = new forkMonitor();
        usaforkMonitor A = new usaforkMonitor(forkm);  
        usaforkMonitor B = new usaforkMonitor(forkm);
        usaforkMonitor C = new usaforkMonitor(forkm);
        usaforkMonitor D = new usaforkMonitor(forkm);
        usaforkMonitor E = new usaforkMonitor(forkm);
        A.start(); B.start(); C.start(); D.start(); E.start();
        A.join(); B.join(); C.join(); D.join(); E.join();
      }
}
