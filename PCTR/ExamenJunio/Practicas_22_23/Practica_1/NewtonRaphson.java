import java.util.Scanner;
import java.util.*;

public class NewtonRaphson {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Introduzca la aproximacion inicial:  ");
        double   x = s.nextDouble();
        System.out.println("Introduzca el numero de iteraciones a realizar:  ");
        int     n = s.nextInt();
        double xN = 0, xN1 = 0;
        xN = x;

        System.out.println ("Introduzca que desea calcular: \n [1] Coseno en [0, 1]\n [2] Exponencial en [2, 3]");
        int     op = s.nextInt();

        switch (op) {
            case 1:
                if (x < 0 || x > 1) System.out.println ("ERROR. Aproximacion inicial fuera del rango [0, 1]");
                else {
                    for (int i = 0; i < n; i++) {
                        if (ffcos(xN) != 0)
                        {
                            xN1 = xN - (fcos(xN) / ffcos(xN));
                            System.out.println("Iteracion: " + i);
                            System.out.println("Aproximacion: " + xN1);
                            xN = xN1;
                        }
                    }
                    System.out.println("Resultado: " + xN);
                }
                break;
            case 2:
                if (x < 2 || x > 3) System.out.println ("ERROR. Aproximacion inicial fuera del rango [2, 3]");
                else {
                    for (int i = 0; i < n; i++) {
                        if (ffexp(xN) != 0)
                        {
                            xN1 = xN - (fexp(xN) / ffexp(xN));
                            System.out.println("Iteracion: " + i);
                            System.out.println("Aproximacion: " + xN1);
                            xN = xN1;
                        }
                    }
                    System.out.println("Resultado: " + xN);
                }
                break;
            default:
               System.out.println ("ERROR. No ha seleccionado una de las opciones posibles"); 
                break;
        }
        
    }

    public static double fcos(double xN){
        return Math.cos(xN) - Math.pow(xN, 3);
    }

    public static double ffcos(double xN){
        return (-Math.sin(xN)) - Math.pow(3*xN, 2);
    }
    
    public static double fexp(double xN){
        return Math.pow(xN, 2) - 5;
    }
    
    public static double ffexp(double xN){
        return 2*xN;
    }
}
