/**
 * numPerfectos.java.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class numPerfectos {
    public static void main(String[] args) throws Exception{
        int n = Integer.parseInt(args[0]); 	  
        int total = 0;
        long sum;

        long inicTiempo = System.nanoTime();
        for(int i = 1; i <= n; i++){
            sum = 0;
            for(int j = 1; j < i; j++)
                if(i % j == 0) sum += j;
            if(i == sum)
                total++;
        }
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("Encontrados " + total + " en " + tiempoTotal + " ms");
	}
}
