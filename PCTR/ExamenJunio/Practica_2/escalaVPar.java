import java.util.Scanner;
import java.util.*;

public class escalaVPar extends Thread{

	public int ini;
	public int fin;
	public static int[] datos = new int[4 * (int)Math.pow(10, 6)];
	public static int escalar = 3;

	public escalaVPar (int i, int f, int[] d, int e) {
		this.ini = i;
		this.fin = f;
		this.datos = d;
		this.escalar = e;
	}

	public void run () {
		for (int i = ini; i <= fin ;i++)
			datos[i] = datos[i] * escalar;
	}

	public static void main(String[] args) throws Exception {
		for(int i = 0; i < datos.length; i++)
			datos[i] = (int)Math.random();
		
		Thread h1 = new escalaVPar(0, datos.length/2 - 1, datos, escalar);
		Thread h2 = new escalaVPar(datos.length/2, datos.length - 1, datos, escalar);
		
		h1.start(); 
		h2.start();
		h1.join();
		h2.join();
	}
}