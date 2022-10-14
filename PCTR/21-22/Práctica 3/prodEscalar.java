import java.util.Arrays;

public class prodEscalar {
    public static int n = 100000000;
    public static int v1[] = new int[n];
    public static int v2[] = new int[n];

    public static int[] inicializar(int[] v, int n)
    {
        for(int i = 0; i < n ; i++)
        {
            v[i] = i;
        }
        return v;
    }
    public static void main(String[] args)
    {
        //Inicializamos los vectores
        v1 = inicializar(v1,n);
        v2 = inicializar(v2,n);
        long result = 0;
        long inicTiempo = System.nanoTime();
        for(int i = 0; i < n; i++)
        {
            result += v1[i] * v2[i];
        }
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("El resultado es = " + result);
        System.out.println("Calculo realizado en " + tiempoTotal + " Milisegundos");
    }
}


