/**
 * usaProdConAn.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 19/12/2021
 */

public class usaProdConAn extends Thread{
    public static long iterations = 1000000;
    public prodConAN pc;
    public int tipoHebra;
    
    public usaProdConAn(prodConAN pc, int tH){
        this.pc = pc;
        this.tipoHebra = tH;
    }
    
    public void run(){
        switch (tipoHebra){
            case 0:
                try {
                    pc.Append(10000);
                } catch (InterruptedException e) {}
            break;
            case 1:
                try {
                    pc.Take();
                } catch (InterruptedException e) {}
            break;
        }
    }
    
    public static void main(String[] args) throws Exception{
        prodConAN pc = new prodConAN();
        usaProdConAn A = new usaProdConAn(pc, 0);   
        usaProdConAn B = new usaProdConAn(pc, 1);  

        A.start(); B.start();
        A.join(); B.join();
    }
}
