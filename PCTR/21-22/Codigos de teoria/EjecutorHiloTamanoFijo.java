import java.util.concurrent.*;

class Tarea implements Runnable {
	public static int cont = 0;

	public Tarea() {}
	
	public void run() {
		for (int i = 0; i < 1000000; i++)
			cont++;
	}
}

public class EjecutorHiloTamanoFijo {

	public static void main(String[] args) throws Exception {
		ExecutorService ejecutor = Executors.newFixedThreadPool(500);

		for (int i = 0; i < 1000; i++)
			ejecutor.execute(new Tarea());

		ejecutor.shutdown();
		while (!ejecutor.isTerminated());
		
		System.out.println(Tarea.cont);
	}