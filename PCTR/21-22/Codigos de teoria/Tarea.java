public class Tarea implements Runnable {
	int numTarea;

	public Tarea(int n) {
		numTarea = n;
	}

	public void run() {
		for (int i = 1; i < 100; i++) {
			System.out.println("Esta es la tarea numero: " + numTarea + "imprimiendo" + i);
		}
	}
}