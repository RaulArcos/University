/**
 * concursoLambda.java 
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class concursoLambda{
    public static int c = 0;
    public static void main(String[] args) throws Exception {
		Runnable t1 = () -> { for(int i = 0; i < 10000; ++i) ++c; };
		Runnable t2 = () -> { for(int i = 0; i < 10000; ++i) --c; };
		
		Thread h1 = new Thread(t1);
		Thread h2 = new Thread(t2);
		
		h1.start(); h2.start();
		h1.join(); h2.join();
		
		System.out.println(c);
	}
}