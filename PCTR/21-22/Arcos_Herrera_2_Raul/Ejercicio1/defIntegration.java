/**
 * defIntegration.java
 * @author Raúl Arcos Herrera, 77175935X
 * @version 17/06/2022
 * 
 */

import java.util.concurrent.*;
import java.math.*;
import java.util.*;

public class defIntegration{
    public static void main (String[] args){
        int numHebras = 6;

        //Creamos una threadPool de 6 hebras para dividirlo en los 6 intervalos de la integral.
        ThreadPoolExecutor ept = new ThreadPoolExecutor(numHebras, numHebras, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());

        for(int i = 0; i < numHebras; i++){
            ept.execute(new tareaDefIntegracion(i, i+1)); //Ejecutamos cada hebra con un intervalo del 0 hasta el 6 yendo de 1 en 1. [0,1][1,2]...
        }

        //FALTA: Juntar cada valor devuelto por cada tarea y sumarlo.

        ept.shutdown();
        while(!ept.isTerminated());
    }
}

class tareaDefIntegracion implements Runnable{

    private int tam = 1000000;
    private int inf;
    private int contador_exito  = 0;

    public void run(){
        for(int i = 0; i < tam; ++i)
        {
            double coordenada_x = Math.random() + inf; //Solo queremos valores de x que se encuentren en el intervalo en el que estamos trabajando. ([0,1] de 0-1 + 0).
            double coordenada_y = Math.random(); 
            if(( coordenada_y < (2* Math.pow(coordenada_x,4)) / (3* Math.pow(coordenada_x, 6) + 3))) //Método Monte Carlo.
                contador_exito++; //Sumamos los Éxitos.
        } 
        double resultadoparcial = contador_exito/tam; //Resultado del intervalo.
    }
    public tareaDefIntegracion(int inf,int sup){
        this.inf = inf;
    }
}