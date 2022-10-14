import java.util.Random;

public class prodMatricesSecuencial {
    
    public static int n = 2000;
    public static int m1[][] = new int[n][n];
    public static int m2[][] = new int[n][n];
    public static int r[][] = new int [n][n];
    static Random rand = new Random();


    public static int[] inicializarVector(int[] v, int n)
    {
        
        for(int i = 0; i < n ; i++) v[i] =  rand.nextInt();
        return v;
    }

    public static int[][] inicializarMatriz(int[][] m, int n)
    {
        for(int i = 0; i < n ; i++)
            for(int j = 0; j < n; j++) 
                m[i][j] =  rand.nextInt();;
        
        return m;
    }

    public static void main(String[] args)
    {   
        System.out.println("Inicializando...");
        //Inicializamos la matriz y el vector con valores random
        m1 = inicializarMatriz(m1, n);
        m2 = inicializarMatriz(m2, n);
        

        //Comenzamos el cronómetro
        long inicTiempo = System.nanoTime();

        System.out.println("Calculando...");
        //Realizamos el cálculo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r[0].length; j++) {
                for (int k = 0 ; k < r[0].length; k++) { 
                    r[i][j] += (m1[i][k] * m2[k][j]);    
                }
            }
        }
        
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("Calculo realizado en " + tiempoTotal + " Milisegundos");
    }
}
