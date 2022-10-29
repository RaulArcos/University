/**
 * matVector.java Realiza el producto entre un vector y una matriz.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class prodEscalarParalelo extends Thread{
    //Atributos de la clase
    public static int n = 1000000;
    public static int v1[] = new int[n];
    public static int v2[] = new int[n];
    
    public static int numHilos = 10;
    public static int tamDivision = n/numHilos;
    public static long productoParcial[] = new long[numHilos];

    private int _id;
    private int _inicio;
    private int _final;

    /**
     * inicializar.
     * @param v
     * @param n
     * @return un vector con valores de 0 hasta n.
     */
    public static int[] inicializar(int[] v, int n){
        for(int i = 0; i < n ; i++)
            v[i] = 5;
        return v;
    }
    
    /**
     * prodEscalarParalelo, constructor.
     * @param idHilo
     * @param ini
     * @param fin
     */
    public prodEscalarParalelo(int idHilo, int ini, int fin){
        _id = idHilo;
        _inicio = ini;
        _final = fin;
    }

    public void run(){
		for(int i = _inicio; i < _final; ++i)
			productoParcial[_id] += (v1[i] * v2[i]);
	}

    public static void main(String[] args) throws Exception{
        //Inicializamos ambos vectores
        v1 = inicializar(v1,n);
        v2 = inicializar(v2,n);
        long result = 0;

        //Creamos un vector de Hilos
        prodEscalarParalelo[] vHilos = new prodEscalarParalelo[numHilos];
        int secVector = 0;

        //Creamos los hilos con las secciones del vector divididas.
        for(int i = 0; i < numHilos; i++){
            vHilos[i] = new prodEscalarParalelo(i, secVector, secVector+tamDivision);
            secVector+=tamDivision;
        }
        
        //Iniciamos todos los hilos y contamos el tiempo
        long inicTiempo = System.nanoTime();
        for(int i = 0; i < numHilos; i++) vHilos[i].start();
        for(int i = 0; i < numHilos; i++) vHilos[i].join();
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        
        //Sumamos el resultado de todos los parciales.
        for(int i = 0; i < numHilos; i++) result += productoParcial[i];
        
        System.out.println("Se ha dividido en " + numHilos + " bloque/s de " + tamDivision);
        System.out.println("El resultado es = " + result);
        System.out.println("Calculo realizado en " + tiempoTotal + " Milisegundos");

    }

}
