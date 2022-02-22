import java.util.*;
class ejercicio3
{
    static public Float max (Vector<Float> v)
    {
        float max = 0;
        for (int i = 0; i < v.size(); i++) 
        {
            if(v.get(i) > max)
                max = v.get(i);
        }
        return max;
    } 
    
    static public Float min (Vector<Float> v)
    {
        float min = v.get(0);
        for (int i = 1; i < v.size(); i++) 
        {
            if(v.get(i) < min)
                min = v.get(i);
        }
        return min;
    }

    static public Float suma (Vector<Float> v)
    {
        float suma = 0;
        for (int i = 0; i < v.size(); i++) 
        {
           suma += v.get(i);
        }
        return suma;
    }
    
    static public Float mul (Vector<Float> v)
    {
        float mul = 1;
        for (int i = 0; i < v.size(); i++) 
        {
           mul = v.get(i) * mul;
        }
        return mul;
    }

    public static void main(String[] args)
    {   
    
        float n = 0;
        Vector<Float> v = new Vector<Float>();
        Scanner in = new Scanner(System.in);

        while(n >= 0)
        {
            System.out.print("Introduce un numero cualquiera: ");
            n = in.nextFloat();
            if(n >= 0)
                v.add(n);
        }
        in.close();
        System.out.println("Se ha introducido un numero negativo");
        System.out.print("RESULTADOS:\n[MAX] = " + max(v) + "\n[MIN] = " + min(v) + "\n[SUMA] = " + suma(v) + "\n[MULT] = " + mul(v));
    }
}