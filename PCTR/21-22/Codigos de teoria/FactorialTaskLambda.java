import java.util.concurrent.*;

public class FactorialTaskLambda{   
    public static void main(String[] args) throws Exception{
        int number=5;
        Callable<Integer> computation = () ->{int fact = 1;
        									  for(int count = number; count > 1; count--) {
        									  	fact = fact * count;}
        									  return (new Integer(fact));
        									 };
        ExecutorService exec = Executors.newFixedThreadPool(1);
        Future<Integer> future = exec.submit(computation);
        exec.shutdown ();
        System.out.println(future.get().intValue());
    }
}