import java.util.Scanner;
import java.util.*;

public class usaComplejos {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Introduzca el numero REAL:  ");
        double x = s.nextDouble();
        System.out.println("Introduzca el numero IMAGINARIO:  ");
        double y = s.nextDouble();
        System.out.println("Complejo creado -> z = " + x + " + (" + y + "i)");
        
        double a = 0, b = 0;
        Complejos c1 = new Complejos (x, y);
        Complejos c2;
        Complejos result = new Complejos (0, 0);

        System.out.println ("Introduzca que desea calcular: \n [1] Suma\n [2] Resta\n [3] Producto\n [4] Cociente\n [5] Modulo\n");
        int op = s.nextInt();

        switch (op) {
            case 1:
                System.out.println("Introduzca el numero REAL que queramos sumar:  ");
                a = s.nextDouble();
                System.out.println("Introduzca el numero IMAGINARIO que queramos sumar:  ");
                b = s.nextDouble();
                System.out.println("Complejo operando 1 -> z = " + x + " + (" + y + "i)");
                System.out.println("Complejo operando 2 -> z = " + a + " + (" + b + "i)");
                c2 = new Complejos (a, b);
                result = Complejos.suma(c1, c2);
                System.out.println("Complejo resultante -> z = " + result.complejo[0] + " + (" + result.complejo[1] + "i)");
                break;
            case 2:
                System.out.println("Introduzca el numero REAL que queramos restar:  ");
                a = s.nextDouble();
                System.out.println("Introduzca el numero IMAGINARIO que queramos restar:  ");
                b = s.nextDouble();
                System.out.println("Complejo operando 1 -> z = " + x + " + (" + y + "i)");
                System.out.println("Complejo operando 2 -> z = " + a + " + (" + b + "i)");
                c2 = new Complejos(a, b);
                result = Complejos.resta(c1, c2);
                System.out.println("Complejo resultante -> z = " + result.complejo[0] + " + (" + result.complejo[1] + "i)");
                break;
            case 3:
                System.out.println("Introduzca el numero REAL que queramos multiplicar:  ");
                a = s.nextDouble();
                System.out.println("Introduzca el numero IMAGINARIO que queramos multiplicar:  ");
                b = s.nextDouble();
                System.out.println("Complejo operando 1 -> z = " + x + " + (" + y + "i)");
                System.out.println("Complejo operando 2 -> z = " + a + " + (" + b + "i)");
                c2 = new Complejos(a, b);
                result = Complejos.producto(c1, c2);
                System.out.println("Complejo resultante -> z = " + result.complejo[0] + " + (" + result.complejo[1] + "i)");
                break;
            case 4:
                System.out.println("Introduzca el numero REAL que queramos dividir:  ");
                a = s.nextDouble();
                System.out.println("Introduzca el numero IMAGINARIO que queramos dividir:  ");
                b = s.nextDouble();
                System.out.println("Complejo operando 1 -> z = " + x + " + (" + y + "i)");
                System.out.println("Complejo operando 2 -> z = " + a + " + (" + b + "i)");
                c2 = new Complejos(a, b);
                result = Complejos.cociente(c1, c2);
                System.out.println("Complejo resultante -> z = " + result.complejo[0] + " + (" + result.complejo[1] + "i)");
                break;
            case 5:
                double modulo = Complejos.modulo(c1);
                System.out.println("Modulo resultante -> " + modulo);
                break;
            default: 
                result.complejo[0] = 0;
                result.complejo[1] = 0;
                break;
                        
        }
    }
}