import java.util.concurrent.*;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.Vector;

public class divCallable implements Callable <Float> { //Dentro de los < > poner el tipo con el que se trata
    private float start, end;

    public divCallable (float s, float e) {
        start = s;
        end = e;
    }

    //IMPORTANTE PORQUE ES CALLABLE, se necesita metodo call
    public Float call () {/*Hacer cosas*/} 

    public static void main (String[] args) throws Exception{
        //Siempre se necesita el objeto Future para recoger los datos
        Vector<Future<Float>> intervalos = new Vector<Future<Float>>();        

        //ThreadPool
        ThreadPoolExecutor etp = (ThreadPoolExecutor)Executors.newFixedThreadPool(subint);

        //Pedir datos
        
        //Division de los datos
        float desp = ((float)(Math.abs(a - b) / subint)), start = 0f, end = desp, integral = 0f;
        for (int i = 0; i < subint; i++) {
            intervalos.addElement(etp.submit(new divCallable(start, end)));
            start = end;
            end = end + desp;
        }  

        etp.shutdown();
        while(!etp.isTerminated());

        //Recoger datos del objeto Future
        try {for (int i = 0; i < subint; i++) integral = integral + intervalos.get(i).get(); } catch (InterruptedException e){} catch (ExecutionException e) {}
    }
}