/**
 * @author Raul Arcos Herrera
 */

public class usaProdCon extends Thread{

    boolean prod;
    PCMonitor m;

    public usaProdCon(boolean prod, PCMonitor m){
        this.prod = prod;
        this.m = m;
    }
  
    public void run(){
        
        if(prod){
            for(int i = 0; i < 100; ++i){
                System.out.println("Thread " + Thread.currentThread().getName() + " Produce " + i);
                m.Append(i);
            }
        }
        else{
            for(int i = 0; i < 100; ++i){
                i = m.Take();
                System.out.println("Thread " + Thread.currentThread().getName() + " Consume " + i);
            }
        }
    }
    
    public static void main(String[] args) throws InterruptedException
    {
        PCMonitor m = new PCMonitor();
        usaProdCon A = new usaProdCon(true, m);
        usaProdCon B = new usaProdCon(false, m);
        usaProdCon C = new usaProdCon(false, m);
        usaProdCon D = new usaProdCon(false, m);
        usaProdCon E = new usaProdCon(false, m);
        usaProdCon F = new usaProdCon(false, m);

        A.start(); A.join();
        B.start(); B.join();
        C.start(); C.join();
        D.start(); D.join();
        E.start(); E.join();
        F.start(); F.join();
    }
}
