/**
 * prodMatricesParalelo.java.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.*;

class tareaProdMatrices implements Runnable{
    private int _Inicio;
    private int _Fin;
    private int[][] _m1;
	private int[][] _m2;
	private static int[][] _r;

    public void run(){
        for (int i = _Inicio; i < _Fin; i++) {
            for (int j = 0; j < _r[0].length; j++) {
                for (int k = 0 ; k < _r[0].length; k++) { 
                    _r[i][j] += (_m1[i][k] * _m2[k][j]);    
                }
            }
        }
	}
    /**
     * Constructor de la clase
     * @param ini
     * @param fin
     * @param m1
     * @param m2
     * @param r
     */
    public tareaProdMatrices(int ini, int fin,int[][] m1, int[][] m2, int[][] r){
		_Inicio = ini;
        _Fin = fin;
        _m1 = m1;
        _m2 = m2;
        _r = r;
	}

}
public class prodMatricesParalelo{
    
    public static int n = 2000;
    public static void main(String[] args) throws Exception{
       
        //Inicializamos la matriz y el vector con valores random

        int m1[][] = new int[n][n];
        int m2[][] = new int[n][n];
        int r[][] = new int [n][n];

        Random rand = new Random();
        System.out.println("Inicializando...");
        
        for(int i = 0; i < n ; i++)
            for(int j = 0; j < n; j++) {
                m1[i][j] = rand.nextInt(10);;
                m2[i][j] = rand.nextInt(10);;
            }    

        int nPuntos = n;
    	int nTareas = 16;
    	int tVentana = nPuntos/nTareas;
    	int linf = 0;
    	int lsup = tVentana;

        long inicTiempo = System.nanoTime();
        System.out.println("Calculando...");

        ThreadPoolExecutor ept = new ThreadPoolExecutor(nTareas, nTareas, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());
        ept.prestartAllCoreThreads();

        for( int i = 0; i < nTareas; ++i ){
    		ept.execute(new tareaProdMatrices(linf, lsup, m1, m2, r));
    	  	linf = lsup + 1;
    	  	lsup += tVentana;
    	}
    	ept.shutdown();

        boolean fin = false;
  		while ( !fin )	//Espera hasta que terminen todas las tareas
  			try { 
  				fin = ept.awaitTermination(20, TimeUnit.SECONDS); 
			} catch( InterruptedException e) {}


        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;

        /*
        for(int i = 0; i < n; i++)
        {
            System.out.println(Arrays.toString(m1[i]) + " * " + Arrays.toString(m2[i]) + "=" + Arrays.toString(r[i]));   
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r[0].length; j++) {
                for (int k = 0 ;k < r[0].length; k++) { 
                    System.out.print(m1[i][k] + " * " + m2[k][j] + " + ");
                }
                System.out.println(" = " + r[i][j]);
            }
        }
        */
        //System.out.println("Se ha dividido en " + numHebras + " bloque/s de " + tamDivision + " Filas");
        System.out.println("Calculo realizado en " + tiempoTotal + " Milisegundos");
    }
}
