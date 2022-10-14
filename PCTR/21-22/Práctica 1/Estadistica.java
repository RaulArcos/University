package EntregaP1;
import java.util.Scanner;
import java.lang.Math;

public class Estadistica {
    
    public static double media(int n, int nube[])
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nube[i];
        }
        return (double) sum/n;
	}
	
    public static double varianza(int n, int nube[], double media)
    {
        double sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum+= Math.pow((nube[i] - media), 2);
        }
        return (double) sum/n;
    }

    public static double desviacionTipica(double varianza)
    {   
        return Math.sqrt(varianza);
    }
    public static void main(String[] args)
    {
        int n = Integer.parseInt(args[0]);
        //Pasamos el contenido de args a nube para tener un código más legible
        int nube[] = new int[n];
        for (int i = 1; i <= n; i++)
        {
            nube[i-1] = Integer.parseInt(args[i]);
        }

        System.out.print("Estadisticas disponibles:\n [1] Media\n [2] Varianza\n [3] Desviacion tipica\n");
        
        Scanner in = new Scanner(System.in);
        int op = in.nextInt();

        switch(op)
        {
            case 1: System.out.println("La media es = " + media(n,nube)); break;
            case 2: System.out.println("La varianza es = " + varianza(n,nube,media(n,nube))); break;
            case 3: System.out.println("La varianza es = " + desviacionTipica(varianza(n,nube,media(n,nube)))); break;
            default: break;
        }

        in.close();
    }




}
