import java.rmi.*;
import java.rmi.registry.*;
import java.util.Scanner;
import java.util.Arrays;

public class cCuaternion {
    public static int tam = 4;

    public static void main (String[] args) throws Exception {
        float q1[] = new float[tam];
        float q2[] = new float[tam];
        float q[] = new float[tam];
        float p, trazaq;
        Scanner s = new Scanner (System.in);

        ICuaternion RefObRemoto = (ICuaternion)Naming.lookup ("//localhost:/cuaternion");
        
        System.out.println("Los servicios son:\n Suma\n Conjugado\n Escalado\n Traza\n");
        System.out.println("Introduzca el primer cuaternion: ");

        for (int i = 0; i < q1.length; i++) q1[i] = s.nextFloat();
        
        System.out.println("Introduzca el segundo cuaternion: ");

        for (int i = 0; i < q2.length; i++) q2[i] = s.nextFloat();
        
        q = RefObRemoto.sumCuaternion(q1, q2);
        System.out.println ("Suma: " + Arrays.toString(q));

        q = RefObRemoto.conCuaternion(q1);
        System.out.println ("Conjugado: " + Arrays.toString(q));

        System.out.println("Introduzca el float: ");
        p = s.nextFloat();

        q = RefObRemoto.xCuaternion(q1, p);
        System.out.println ("Escalado: " + Arrays.toString(q));
        
        trazaq = RefObRemoto.tCuaternion(q1);
        System.out.println ("Traza: " + trazaq);
    }
}
