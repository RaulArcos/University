import java.util.Scanner;
import java.util.*;

public class Usa_hebra extends Thread{
    public static void main (String [] args) throws Exception {
        hebra p = new hebra (1000000, 0);
        hebra q = new hebra (1000000, 1);

        p.start();
        q.start();
        p.join();
        q.join();
        
        System.out.println (hebra.n());
    }
}