/**
 * matVector.java Realiza el producto entre un vector y una matriz.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
import java.util.Random;

public class matVector {
    
    public static int n = 50000;
    public static int m[][] = new int[n][n];
    public static int v[] = new int[n];
    public static int r[] = new int [n];
    static Random rand = new Random();

    /**
     * inicializarVector, llega un vector con valores random.
     * @param v
     * @param n
     * @return un vector.
     */
    public static int[] inicializarVector(int[] v, int n){   
        for(int i = 0; i < n ; i++) v[i] =  rand.nextInt();
        return v;
    }

    /**
     * inicializarMatriz, llena una matriz con valores random.
     * @param m
     * @param n
     * @return una matriz.
     */
    public static int[][] inicializarMatriz(int[][] m, int n){
        for(int i = 0; i < n ; i++)
            for(int j = 0; j < n; j++) 
                m[i][j] =  rand.nextInt();;
        
        return m;
    }

    public static void main(String[] args){   
        System.out.println("Inicializando...");
        //Inicializamos la matriz y el vector con valores random
        m = inicializarMatriz(m, n);
        v = inicializarVector(v, n);

        //Comenzamos el cronómetro
        long inicTiempo = System.nanoTime();

        System.out.println("Calculando...");
        //Realizamos el cálculo
        for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				r[i] += v[i] * m[i][j];
        
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("Calculo realizado en " + tiempoTotal + " Milisegundos");
    }
}
