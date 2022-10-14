import java.util.Scanner;
import java.util.*;

public class Complejos {
    public double complejo[] = new double[2];
        
    public Complejos (double x, double y){
        this.complejo[0] = x;
        this.complejo[1] = y;
    }

    public static Complejos suma (Complejos c1, Complejos c2){
        Complejos result = new Complejos(0, 0);
        result.complejo[0] = c1.complejo[0] + c2.complejo[0];
        result.complejo[1] = c1.complejo[1] + c2.complejo[1];

        return result;
    }

    public static Complejos resta (Complejos c1, Complejos c2){
        Complejos result = new Complejos(0, 0);
        result.complejo[0] = c1.complejo[0] - c2.complejo[0];
        result.complejo[1] = c1.complejo[1] - c2.complejo[1];

        return result;
    }

    public static Complejos producto (Complejos c1, Complejos c2){
        Complejos result = new Complejos(0, 0);
        result.complejo[0] = c1.complejo[0] * c2.complejo[0] - c1.complejo[1] * c2.complejo[1];
        result.complejo[1] = c1.complejo[0] * c2.complejo[1] + c1.complejo[1]* c2.complejo[0];

        return result;
    }

    public static Complejos cociente (Complejos c1, Complejos c2){
        Complejos result = new Complejos(0, 0);
        result.complejo[0] = (c1.complejo[0] * c2.complejo[0] + c1.complejo[1] * c2.complejo[1]) / (Math.pow(c2.complejo[0], 2)/Math.pow(c2.complejo[1], 2));
        result.complejo[1] = (c1.complejo[1] * c2.complejo[0] - c1.complejo[0] * c2.complejo[1]) / (Math.pow(c2.complejo[0], 2)/Math.pow(c2.complejo[1], 2));

        return result;
    }

    public static double modulo (Complejos c){

        return Math.sqrt(Math.pow(c.complejo[0], 2) + Math.pow(c.complejo[1], 2));
    }
}