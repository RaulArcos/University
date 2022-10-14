public class Prioridades extends Thread {
	private long dato;
	private static int prio = 4; //atributo de clase comun a instancias

	private long fac(long n) {
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else return (fac(n - 1) * n);
	}


	public void run() {
		//this.setPriority(prio++); //ejecutar con y sin el ajuste de prioridad
		System.out.println("El factorial de " + dato + " es " + fac(dato));
	}

	
	
	public static void main(String[] args) {
		new Prioridades(10).start(); //orden lanzamiento no es igual al orden
		new Prioridades(20).start(); //de ejecucion... pero
		new Prioridades(30).start(); //ajustando las prioridades?
		new Prioridades(40).start();
		new Prioridades(50).start();
		new Prioridades(60).start();
	}
}