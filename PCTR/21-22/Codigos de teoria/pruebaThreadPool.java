import java.util.concurrent.*;

public class pruebaThreadPool {
	
	public static void main(String[] args) {
		
		int nTareas = Integer.parseInt(args[0]);
		int tamPool = Integer.parseInt(args[1]);

		ThreadPoolExecutor miPool = new ThreadPoolExecutor(tamPool, tamPool, 60000L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue < Runnable > ());

		Tarea[] tareas = new Tarea[nTareas];
		
		for (int i = 0; i < nTareas; i++) {
			tareas[i] = new Tarea(i);
			miPool.execute(tareas[i]);
		}

		miPool.shutdown();
	}
}