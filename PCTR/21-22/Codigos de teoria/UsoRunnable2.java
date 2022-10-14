/* 
 * Otra forma de crear hilos concurrentes dandoles nombre
 * @author Antonio J. Tomeu
 */
public class UsoRunnable2 implements Runnable {
	private int Iter;

	public UsoRunnable2(int Dato) {
		Iter = Dato;
	}

	public void run() {
		for (int i = 1; i <= Iter; i++)
			System.out.println("Trabajando");
	}
	public static void main(String[] args) throws InterruptedException {
		Runnable HiloA = new UsoRunnable2(100);
		Runnable HiloB = new UsoRunnable2(200);
		Runnable HiloC = new UsoRunnable2(100);

		//version del constructor Thread crea hilo con un nombre
		Thread A = new Thread(HiloA, "Mi Hilo");
		Thread B = new Thread(HiloB, "Tu Hilo"); //sin nombre
		Thread C = new Thread(HiloC);

		A.start();
		B.start();
		A.join();
		B.join();
		C.join();

		//metodo getName() de objetos de la clase Thread devuelve el nombre
		//del hilo
		System.out.println(A.getName());
		System.out.println(B.getName());
		//no tenia nombre, pero se le dio uno en tiempo de ejecucion.
		System.out.println(C.getName());
	}
}