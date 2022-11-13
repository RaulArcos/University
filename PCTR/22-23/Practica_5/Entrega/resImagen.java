/**
 * resimagen.java.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
import java.util.*;

public class resImagen {
    public static void main(String[] args) throws InterruptedException{
        Random r = new Random();
        int n = 40000;
        int[][] m = new int[n][n];

        //Rellenamos la matriz.
        for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				m[i][j] = r.nextInt(255);
    
        //Iniciamos el contandor
        long inicTiempo = System.nanoTime();

        //Se quita 1 de cada limite para que no viole segmento.
        for(int i = 1; i < m.length - 1; i++)
            for(int j = 1; j < m[i].length - 1; j++) 
                m[i][j] = ((4*m[i][j]) - m[i+1][j] - m[i][j+1] - m[i-1][j] - m[i][j-1])/8;
		
        long finTiempo = System.nanoTime();		//se coge el tiempo despu�s de ejecutar
		System.out.println("Tiempo Total s: " + (finTiempo - inicTiempo) / 1.0e9);	//se coge el tiempo despu�s de ejecutar y se calcula
    }
}
