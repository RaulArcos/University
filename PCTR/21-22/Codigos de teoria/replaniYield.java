public class replaniYield extends Thread {
	private boolean hY; //indicara si el hilo cede prioridad o no..
	private int v;

	public replaniYield(boolean hacerYield, int vueltas) {
		hY = hacerYield;
		v = vueltas;
	}

	public void run() {
		for (int i = 0; i < v; i++)
		if (i == 20 && hY == true) {
			this.yield();
		} //indica cesion de prioridad...
		else System.out.println("Hilo " + this.getName() + " en iteracion " + i);
	}

	public static void main(String[] args) {
		replaniYield h0 = new replaniYield(false, 50);
		replaniYield h1 = new replaniYield(false, 50);
		replaniYield h2 = new replaniYield(true, 50); //cedera prioridad y

		h0.setName("1-NoYield"); //sera o no considerarda
		h1.setName("2-NoYield");
		h2.setName("3-SIYield");

		h0.start();
		h1.start();
		h2.start();
	}
}