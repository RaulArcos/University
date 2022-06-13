import java.util.Scanner;
import java.util.*;

public class Estadistica {
    public static void main(String args[]) {
        int tam = Integer.parseInt(args[0]);
        Scanner s = new Scanner(System.in);
        int     op = 0;
        double   result = 0, media = 0, varianza = 0;
        
        System.out.println ("Introduzca que desea calcular: \n [1] Media\n [2] Varianza\n [3] Desviacion tipica");
        op = s.nextInt();
        
        switch (op) {
            case 1:
                result = media(args, tam);
                System.out.println ("La media es: " + result);
                break;
            case 2:
                media = media (args, tam);
                result = varianza(args, tam, media);
                System.out.println ("La varianza es: " + result);
                break;
            case 3:
                media = media (args, tam);
                varianza = varianza (args, tam, media);
                result = dtipica(varianza);
                System.out.println ("La desviacion tipica es: " + result);
                break;
            default: 
                result = 0;
                break;
                        
        }
        
    }
    
    public static double media(String args[], int tam){
        double result = 0;
        for (int i = 1; i <= tam; i++){
            result = result +  Integer.parseInt(args[i]);
        }
        return result/tam;
    }
    
    public static double varianza(String args[], int tam, double media){
        double result = 0;
        for (int i = 1; i <= tam; i++){
            result = result + Math.pow((Integer.parseInt(args[i]) - media), 2);
        }
        return result/tam;
    }
    
    public static double dtipica(double varianza){
        return Math.sqrt(varianza);
    }
}
