package EntregaP1;
import java.util.Scanner;

public class intDefinidaMonteCarlo { 
    
    public static double f_x(double x)
    {
        return x;
    }
    public static double f_sin(double x)
    {
        return Math.sin(x);
    }

    public static void main(String[] args)
    {   
        System.out.print("Introduce el numero de iteraciones: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
        double contador_exitos_x = 0,contador_exitos_sin = 0;
        for (int i = 0; i < n; i++)
        {
            double coordenada_x =  Math.random();
            double coordenada_y =  Math.random();

            if(coordenada_y <= f_x(coordenada_x))
            {
                contador_exitos_x++;
            }
            if(coordenada_y <= f_sin(coordenada_x))
            {
                contador_exitos_sin++;
            }
        }

        System.out.println("Integral aproximada x = " + contador_exitos_x/n);
        System.out.println("Integral aproximada sin = " + contador_exitos_sin/n);
        
    }
}
