import java.io.*;
import java.util.*;

public class Control extends Thread {
	//No declara constructor explicito. Usa el disponible por defecto
	public void run() {
		for (;;)
			System.out.println("Trabajando");
	}

	public static void main(String[] args) throws IOException {
		int c;
		Control Hilo = new Control(); //usando el constructor implicito
		Hilo.start();

		for (int i = 1; i <= 100; i++) //entrelazado de instrucciones
			System.out.println("Hola soy el padre");

		Hilo.suspend(); //USO DE METODO DEROGADO, HILO PADRE SUSPENDE A HIJO .
		System.out.println("Hijo suspendido");
		//Ahora reactivamos al hijo, que pasa a listo.
		System.out.println("Pulsa 1 para despertar al hijo");

		do {
			c = System. in .read();
		} while (c != -1);

		Hilo.resume(); //USO DE METODO DEROGADO, PASA A LISTO A HIJO
		//un poquito de interfoliacion otra vez.

		for (int i = 1; i <= 100; i++)
			System.out.println("Hola soy el padre");

		Hilo.stop(); //USO DE METODO DEROGADO, PADRE PARA AL HIJO
	}
}