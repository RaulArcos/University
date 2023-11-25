import java.util.Scanner;
import java.util.*;

public class concursoLambda{
    public static int critica = 0;

    public static void main (String[] args) throws Exception{
        Runnable r1 = () -> { for(int i = 0; i < 10000; ++i) ++critica; };
        Runnable r2 = () -> { for(int i = 0; i < 10000; ++i) --critica; };
        
        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);

        t1.start();
        t2.start();
		t1.join();
        t2.join();

        System.out.println(critica);
    }
}