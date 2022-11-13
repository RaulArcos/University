/**
 * resImagenPar.java.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
import java.util.*;
import java.util.concurrent.*;


class tareaResImagen implements Runnable{
	private  int ini;
	private  int fin;
	
	private int[][] m_;
	
	/**
	 * Constructor de la clase
	 * @param i
	 * @param f
	 * @param m
	 */
	public tareaResImagen(int i, int f, int[][] m){
		ini = i;
		fin = f;
		
		m_ = m;
	}
  
	public void run(){
        if(ini == 0) ini = 1;
        if(fin == m_[0].length) fin--;
        for(int i = ini; i < fin - 1; i++)
            for(int j = 1; j < m_[0].length - 1; j++)
                m_[i][j] = ((4*m_[i][j]) - m_[i+1][j] - m_[i][j+1] - m_[i-1][j] - m_[i][j-1])/8;
  	}
}	


public class resImagenPar {
    
    public static void main(String[] args) throws InterruptedException{
        Random r = new Random();
        int n = 40000;
        int[][] m = new int[n][n];

        //Rellenamos la matriz.

        for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				m[i][j] = r.nextInt(255);
        
        int nPuntos = n;
        int nTareas = 14;
        int tVentana = nPuntos/nTareas;
        int linf = 0;
        int lsup = tVentana;
        //Iniciamos el contandor
        long inicTiempo = System.nanoTime();

        ThreadPoolExecutor ept = new ThreadPoolExecutor(nTareas, nTareas, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());
    	ept.prestartAllCoreThreads();
    	
    	for( int i = 0; i < nTareas; ++i ){
    		ept.execute(new tareaResImagen(linf, lsup, m));
    	  	linf = lsup + 1;
    	  	lsup += tVentana;
    	}

        ept.shutdown();
    	
    	boolean fin = false;
  		while ( !fin )	//Espera hasta que terminen todas las tareas
  			try { 
  				fin = ept.awaitTermination(20, TimeUnit.SECONDS); 
			} catch( InterruptedException e) {}

            long finTiempo = System.nanoTime();		//se coge el tiempo despu�s de ejecutar
            System.out.println("Tiempo Total s: " + (finTiempo - inicTiempo) / 1.0e9);
    }
}
