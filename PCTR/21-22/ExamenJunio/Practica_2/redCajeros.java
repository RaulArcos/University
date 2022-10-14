import java.util.Scanner;
import java.util.*;

public class redCajeros{
	public static void main(String[] args) throws Exception {
	    cuentaCorriente cc1  = new cuentaCorriente(1, 500.0);
        cuentaCorriente cc2  = new cuentaCorriente(2, 700.0);
	 	Runnable c1 = new cajero(cc1, 0);
	 	Runnable c2 = new cajero(cc2, 0);

	 	Thread  h1 = new Thread(c1);
	 	Thread  h2 = new Thread(c2);
	 	 
	 	h1.start();
        h2.start();
	 	h1.join();
        h2.join();
    }
}