package EntregaP1;
import java.util.Scanner;

public class usaComplejos {
    
    public static void main(String[] args)
    {
        System.out.println("CALCULADORA DE COMPLEJOS");
        System.out.println("Opciones disponibles: ");
        System.out.print("  [1] Suma\n  [2] Resta\n  [3] Modulo\n  [4] Producto\n  [5] Cociente\nOpcion = ");

        Scanner in = new Scanner(System.in);
        int op = in.nextInt();

        //Cogemos el valor del primer complejo que usaremos si o si.
        System.out.print("Introduce la parte real del primer complejo = ");
        Scanner in2 = new Scanner(System.in);
        int r1 = in.nextInt();
        System.out.print("Introduce la parte imaginaria del primer complejo = ");
        Scanner in3 = new Scanner(System.in);
        int i1 = in.nextInt();
        
        Complejos c1 = new Complejos(r1,i1);
        Complejos c2 = new Complejos();
        //En caso de ser las operaciones 1,2,4,5 necesitaremos otro complejo.
        if(op > 0 && op < 6 && op != 3)
        {  
            System.out.print("Introduce la parte real del segundo complejo = ");
            Scanner in4 = new Scanner(System.in);
            int r2 = in.nextInt();
            System.out.print("Introduce la parte real del segundo complejo = ");
            Scanner in5 = new Scanner(System.in);
            int i2 = in.nextInt();

            c2 = new Complejos(r2,i2);
            in4.close();
            in5.close();
        }

        
        
        switch(op)
        {
            case 1: System.out.println("Resultado = " + Complejos.imprimeComplejos(Complejos.sumaComplejos(c1,c2))); break;
            case 2: System.out.println("Resultado = " + Complejos.imprimeComplejos(Complejos.restaComplejos(c1,c2))); break;
            case 3: System.out.println("Resultado = " + Complejos.modulo(c1)); break;
            case 4: System.out.println("Resultado = " + Complejos.imprimeComplejos(Complejos.sumaComplejos(c1,c2))); break;
            case 5: System.out.println("Resultado = " + Complejos.imprimeComplejos(Complejos.sumaComplejos(c1,c2))); break;
        }
        in.close();
        in2.close();
        in3.close();
    }
    
}
