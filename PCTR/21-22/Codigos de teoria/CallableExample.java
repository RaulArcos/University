import java.util.concurrent.*;

public class FactorialTask implements Callable<Integer> {
    int number;¡
    public Integer call() throws InvalidParamaterException {
        int fact = 1
        for(int count = number; count > 1; count--) {
            fact = fact * count;
        }
        return (new Integer(fact));
    }
    
    public static void main(String args[0])
    	FactorialTask task = new FactorialTask(5);
    	Future<Integer> future = executorService.submit(task);
    	System.println(future.get().intValue());
}