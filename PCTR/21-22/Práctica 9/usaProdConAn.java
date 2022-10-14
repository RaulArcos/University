public class usaProdConAn extends Thread {
    
    boolean prod;
    prodConAN prodConAN;

    public usaProdConAn(boolean prod, prodConAN prodConAN){
        this.prod = prod;
        this.prodConAN = prodConAN;
    }
  
    public void run(){
        
        if(prod){
            for(int i = 0; i < 100; ++i){
                try{prodConAN.Append(i);}catch (InterruptedException e){} 
                System.out.println("Thread " + Thread.currentThread().getName() + " Produce " + i);
                
            }
        }
        else{
            for(int i = 0; i < 100; ++i){
                try{i = prodConAN.Take();}catch (InterruptedException e){}  
                System.out.println("Thread " + Thread.currentThread().getName() + " Consume " + i);
            }
        }
    }
    
    public static void main(String[] args) throws Exception
    {
        prodConAN prodConAN = new prodConAN();
        usaProdConAn A = new usaProdConAn(true, prodConAN);
        usaProdConAn B = new usaProdConAn(false, prodConAN);

        A.start(); A.join();
        B.start(); B.join();

    }
}
