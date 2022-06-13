import java.util.Scanner;
import java.util.*;
 
public class intDefinidaMonteCarlo {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Introduzca el numero de iteraciones a realizar:  ");
        int     n = s.nextInt();
        double    contador_exitos_x = 0;
        double    contador_exitos_sin = 0;
        for (int i = 0; i < n; i ++)
        {
            double coordenada_x = Math.random();
            double coordenada_y = Math.random();
            if (coordenada_y <= f_x(coordenada_x)) contador_exitos_x++;
            if (coordenada_y <= f_sin(coordenada_x)) contador_exitos_sin++;
        }
        System.out.println("Integral aproximada f(x) = x -> " + contador_exitos_x/n); 
        System.out.println("Integral aproximada f(x) = sin(x) -> " + contador_exitos_sin/n); 
    }
    
    public static double f_x(double x) {
        return x;
    }
    
    public static double f_sin (double x){
        return Math.sin(x);
    }
}
