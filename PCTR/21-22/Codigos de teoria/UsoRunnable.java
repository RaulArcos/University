public class UsoRunnable implements Runnable {
	private String Cadena;

	public UsoRunnable(String Palabra) {
		Cadena = Palabra;
	}

	public void run() {
		for (;;)
			System.out.println(Cadena);
	}

	public static void main(String[] args) {
		Runnable Hilo1 = new UsoRunnable("Hola");
		Runnable Hilo2 = new UsoRunnable("Adios");
		new Thread(Hilo1).start();
		new Thread(Hilo2).start();
	}
}