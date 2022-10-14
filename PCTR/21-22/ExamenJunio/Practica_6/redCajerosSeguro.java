/**
 * redCajerosSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

public class redCajerosSeguro{
	public static void main(String[] args) throws Exception {
        Object obj = new Object();

	    cuentaCorrienteSeguro cc1  = new cuentaCorrienteSeguro(1, 500.0, obj);
        cuentaCorrienteSeguro cc2  = new cuentaCorrienteSeguro(2, 700.0, obj);
	 	Runnable c1 = new cajeroSeguro(cc1, 0, obj);
	 	Runnable c2 = new cajeroSeguro(cc2, 0, obj);

	 	Thread  h1 = new Thread(c1);
	 	Thread  h2 = new Thread(c2);
	 	 
	 	h1.start();
        h2.start();
	 	h1.join();
        h2.join();
    }
}