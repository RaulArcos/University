import java.util.Scanner;

public class NewtonRaphson {

    public static void main(String[] args){   
        
        System.out.print("Introduce el numero de iteraciones: ");
        Scanner in = new Scanner(System.in);
        int iteraciones = in.nextInt();
        
        System.out.println("Funciones a aproximar raiz: \n[1] cos(x) - x^3\n[2] x^2 - 5");
        Scanner in2 = new Scanner(System.in);
        int op = in2.nextInt();
        
        switch(op){
            case 1: funcion1(iteraciones); break;
            case 2: funcion2(iteraciones); break;
            default: break;
        }
    in.close();
    in2.close();
    }  

    public static double f(double x){
		return Math.cos(x) - Math.pow(x, 3);
	}
	public static double fd(double x){
		return -Math.sin(x) - 3*Math.pow(x, 2);
	}
    public static double f2(double x){
        return Math.pow(x, 2) - 5;
    }
    public static double fd2(double x){
        return 2*x;
    }

    public static void funcion1 (int iteraciones){
        System.out.print("Introduce x0 entre 0 y 1: ");
        Scanner in3 = new Scanner(System.in);
        double x0  = in3.nextDouble();
        
        double xN = x0;
        double xN1 = 0;

        for(int i = 0; i <= iteraciones; i++){
            if(fd(xN) != 0)
            {
                xN1 = xN - (f(xN) / fd(xN));
                System.out.println("Iteracion: " + i + "  Aproximacion = " + xN1);
            }
            xN = xN1;
        }
        System.out.print("Resultado = " + xN);
        in3.close();
    }

    public static void funcion2(int iteraciones){
        System.out.print("Introduce x0 entre 2 y 3: ");
        Scanner in4 = new Scanner(System.in);
        double x0  = in4.nextDouble();
        
        double xN = x0;
        double xN1 = 0;

        for(int i = 0; i <= iteraciones; i++){
            if(fd2(xN) != 0){
                xN1 = xN - (f2(xN) / fd2(xN));
                System.out.println("Iteracion: " + i + "  Aproximacion = " + xN1);
            }
            xN = xN1;
        }
        System.out.print("Resultado = " + xN);
        in4.close();
    }  
}