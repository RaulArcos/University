/**
 * numPerfectos.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 09/11/2022
 */

public class numPerfectos {
    public static boolean Perfecto (int n){
        int sum = 0;

        for (int i = 1; i < n; i++)
            if (n % i == 0) sum = sum + i;
        
        if (n == sum)
            return(true);
        return(false);
    }
    public static void main (String[] args) throws Exception {
        long iniciaC = System.nanoTime();

        for (int i = 1; i <= Integer.parseInt(args[0]); i++)
            Perfecto(i);
            
        System.out.println(((System.nanoTime() - iniciaC)/(long)1.0e9) + " s");
    }
}
