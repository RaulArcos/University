/**
 * matVectorConcurrente.java Realiza el producto entre un vector y una matriz de forma concurrente.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
import java.util.Arrays;
import java.util.Random;

public class matVectorConcurrente implements Runnable{
    
    public static int n = 50000;
    public static int numHebras = 2;
    public static int tamDivision = n/numHebras;
    public static long productoParcial[] = new long[numHebras];

    private int _filaInicio;
    private int _filaFin;
    private int[] _v;
	private int[][] _m;
	private int[] _r;

    /**
     * matVectorConcurrente, constructor.
     * @param ini
     * @param fin
     * @param v
     * @param m
     * @param r
     */
    public matVectorConcurrente(int ini, int fin,int[] v, int[][] m, int[] r){
		_filaInicio = ini;
        _filaFin = fin;
        _v = v;
        _m = m;
        _r = r;
	}

    public void run(){
		for(int i = _filaInicio; i < _filaFin; i++)	
			for(int j = 0; j < _r.length; ++j)
				_r[j] += _v[j] * _m[i][j];
	}

    public static void main(String[] args) throws Exception{
       
        //Inicializamos la matriz y el vector con valores random
        int m[][] = new int[n][n];
        int v[] = new int[n];
        int r[] = new int [n];

        Random rand = new Random();
        System.out.println("Inicializando...");
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++) 
                m[i][j] =  rand.nextInt(10);
            v[i] = rand.nextInt(10);
        }

        //Creamos el vector de tareas
        Runnable Tareas;
        Thread[] vHilos = new Thread[numHebras];
        int numFilas = 0;
        
        long inicTiempo = System.nanoTime();
        for(int i = 0; i < numHebras; i++){
            Tareas = new matVectorConcurrente(numFilas, numFilas+tamDivision,v,m,r);
            vHilos[i] = new Thread(Tareas);

            numFilas+=tamDivision;
        }

        System.out.println("Calculando...");
        
        for(int i = 0; i < numHebras; i++) vHilos[i].start();
        for(int i = 0; i < numHebras; i++) vHilos[i].join();
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;

        System.out.println("Se ha dividido en " + numHebras + " bloque/s de " + tamDivision + " Filas");
        System.out.println("Calculo realizado en " + tiempoTotal + " Milisegundos");
    }
}
