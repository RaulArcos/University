import java.util.Scanner;
import java.util.*;

public class escalaVector {
	public static int potencia = 6;
	public static int[] datos = new int[4 * (int)Math.pow(10, potencia)];
	
	public static void main (String[] args) throws Exception {	
		int escalar = 3;
		
		for(int i = 0; i < datos.length; i++) {
			datos[i] = (int)Math.random();
			datos[i] = datos[i] * escalar;
		}
			
	}
}