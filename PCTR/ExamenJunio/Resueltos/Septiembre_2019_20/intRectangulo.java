import java.util.concurrent.*;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.Scanner;
import java.util.Vector;

public class intRectangulo implements Callable <Float>{
    private float a, b;

    public intRectangulo (float a, float b) {
        this.a = a;
        this.b = b;
    }

    public Float call () {return (b-a) * ((3*a*a) + 2);}

    public static void main (String[] args) throws Exception{
        Scanner s = new Scanner (System.in);
        int a, b, subint;
        Vector<Future<Float>> intervalos = new Vector<Future<Float>>();

        System.out.println("Introduzca los extremos a y b: ");
        a = s.nextInt(); b = s.nextInt();

        do {
            System.out.println("Introduzca los subintervalos (par): ");
            subint = s.nextInt();
        } while (subint % 2 != 0 || subint == 0);

        float desp = ((float)(Math.abs(a - b) / subint)), start = 0f, end = desp, integral = 0f;
        ThreadPoolExecutor etp = (ThreadPoolExecutor)Executors.newFixedThreadPool(subint);
        ThreadPoolExecutor etpSec = (ThreadPoolExecutor)Executors.newFixedThreadPool(1);
        
        long iniSec = System.currentTimeMillis();
        etpSec.submit(new intRectangulo(a, b));
        long tiempoSec = System.currentTimeMillis() - iniSec;
        etpSec.shutdown();

        long iniPar = System.currentTimeMillis();
        for (int i = 0; i < subint; i++) {
            intervalos.addElement(etp.submit(new intRectangulo(start, end)));
            start = end;
            end = end + desp;
        }  

        etp.shutdown();
        while(!etp.isTerminated());

        try {
            for (int i = 0; i < subint; i++) integral = integral + intervalos.get(i).get();
        } catch (InterruptedException e){} catch (ExecutionException e) {}
        
        long tiempoPar = System.currentTimeMillis() - iniPar;

        System.out.println ("Resultado: " + integral + "\nTiempo de ejecucion: " + tiempoPar + " ms\nSpeedUp: " + ((double)(tiempoSec/tiempoPar)/1000));
        s.close();
    }
}