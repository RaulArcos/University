class Prueba_Hilo1 //Hace uso de la clase anterior
{
	public static void main(String[] args) throws InterruptedException {
		int tam = 1; 

		Ejemplo_Hilos1 vectorHilos[] = new Ejemplo_Hilos1[tam];

		//Ejemplo_Hilos1 Hilo1 = new Ejemplo_Hilos1(10);
		//Ejemplo_Hilos1 Hilo2 = new Ejemplo_Hilos1(15);
		//Ejemplo_Hilos1 Hilo3 = new Ejemplo_Hilos1(20);
		//Ejemplo_Hilos1 Hilo4 = new Ejemplo_Hilos1(25);

		for(int i = 0; i < tam; i++)
		{
			vectorHilos[i] = new Ejemplo_Hilos1(100000);
		}

		for(int i = 0; i < tam; i++)
		{
			vectorHilos[i].start();
		}
		for(int i = 0; i < tam; i++)
		{
			vectorHilos[i].join();
		}

		/*Hilo1.start(); //Ahora se lanzan ambos hilos...
		Hilo2.start(); //con apertura de co-rutina
		Hilo3.start();
		Hilo4.start();

		Hilo1.join();
		Hilo2.join(); // y cierre de co-rutina
		Hilo3.join();
		Hilo4.join();*/

		System.out.println("Hilos terminados");
	}
}