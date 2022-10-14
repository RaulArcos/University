public class ThreadTestNuevaPrioridad {
	public static void main(String[] args) {
		int nHilos = Integer.parseInt(args[0]);
		long n = Long.parseLong(args[1]);

		Thread t[] = new Thread[nHilos];
		for (int i = 0; i < t.length; i++) {
			t[i] = new Thread(new Trabajo(n, "Trabajo " + i));
			t[i].setPriority((i % 10) + 1);
			t[i].start();
		}

		for (int i = 0; i < t.length; i++) {
			try {
				t[i].join();
			} catch (InterruptedException ie) {}
		}
	}
}