import java.rmi.*;
import java.rmi.registry.*;
import java.util.Scanner;
import java.util.Arrays;

public class cVector {
    public static int tam = 4;

    public static void main (String[] args) throws Exception {
        float q1[] = new float[tam];
        float q2[] = new float[tam];
        float q[] = new float[tam];
        float p, trazaq;
        Scanner s = new Scanner (System.in);

        IVector RefObRemotoS = (IVector)Naming.lookup ("//localhost:/vector");
        IVector RefObRemotoP = (IVector)Naming.lookup ("//localhost:/vector");
        IVector RefObRemotoX = (IVector)Naming.lookup ("//localhost:/vector");
        IVector RefObRemotoT = (IVector)Naming.lookup ("//localhost:/vector");
        
        System.out.println("Los servicios son:\n Suma\n Producto Escalar\n Escalado\n Traza\n");
        System.out.println("Introduzca el primer vector: ");

        for (int i = 0; i < q1.length; i++) q1[i] = s.nextFloat();
        
        System.out.println("Introduzca el vector: ");

        for (int i = 0; i < q2.length; i++) q2[i] = s.nextFloat();
        
        q = RefObRemotoS.sumVecto(q1, q2);
        System.out.println ("Suma: " + Arrays.toString(q));

        q = RefObRemotoP.pEscalVector(q1, q2);
        System.out.println ("Producto escalar: " + Arrays.toString(q));

        System.out.println("Introduzca el float: ");
        p = s.nextFloat();

        q = RefObRemotoX.xVector(q1, p);
        System.out.println ("Escalado: " + Arrays.toString(q));
        
        trazaq = RefObRemotoT.trazaVector(q1);
        System.out.println ("Traza: " + trazaq);
    }
}
