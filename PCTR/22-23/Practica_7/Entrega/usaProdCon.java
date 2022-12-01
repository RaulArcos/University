/**
 * UsaProdCon.java.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class usaProdCon extends Thread{

    boolean prod;
    ProdCon p;

    public usaProdCon(boolean prod, ProdCon p){
        this.prod = prod;
        this.p = p;
    }
  
    public void run(){
        
        if(prod){
            for(int i = 0; i < 100; ++i){
                System.out.println("Thread " + Thread.currentThread().getName() + " Produce " + i);
                p.Append(i);
            }
        }
        else{
            for(int i = 0; i < 100; ++i){
                i = p.Take();
                System.out.println("Thread " + Thread.currentThread().getName() + " Consume " + i);
            }
        }
    }
    
    public static void main(String[] args) throws InterruptedException
    {
        ProdCon p = new ProdCon();
        usaProdCon A = new usaProdCon(true, p);
        usaProdCon B = new usaProdCon(false, p);
        usaProdCon C = new usaProdCon(false, p);
        usaProdCon D = new usaProdCon(false, p);
        usaProdCon E = new usaProdCon(false, p);
        usaProdCon F = new usaProdCon(false, p);

        A.start(); A.join();
        B.start(); B.join();
        C.start(); C.join();
        D.start(); D.join();
        E.start(); E.join();
        F.start(); F.join();
    }
}
