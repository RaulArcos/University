import java.util.concurrent.*;

public class FactorialTask implements Callable<Integer>{
    int number;
    
    public FactorialTask(int number){this.number=number;}
    public Integer call(){
        int fact = 1;
        for(int count = number; count > 1; count--) {
            fact = fact * count;}
        return (new Integer(fact));
    }
   
    public static void main(String[] args) throws Exception{
        FactorialTask task = new FactorialTask(5);
        ExecutorService exec = Executors.newFixedThreadPool(1);
        Future<Integer> future = exec.submit(task);
        exec.shutdown ();
        System.out.println(future.get().intValue());
    }
}