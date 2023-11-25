/**
 * arrSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 15/11/2022
 */

import java.util.Arrays;

public class arrSeguro extends Thread {
    public static int tam = 10;
    public int vector[] = new int [tam];
    private Object obj;
    
    public arrSeguro (Object obj, int vector[]){
        this.obj = obj;
        this.vector = vector;
    }

    public void run(){
        synchronized(obj){
            for (int i = 0; i < tam; i++)
                vector[i] = tam - i;
        }
    }
    public static void main (String[] args) throws Exception {
        Object obj = new Object();
        int tam = 10;

        int vector[] = new int[tam];

        for (int i = 0; i < tam; i++){
            vector[i] = i + 1;
        }

        System.out.println("Vector inicializado: ");
        System.out.println(Arrays.toString(vector));

        Thread A = new Thread (new arrSeguro(obj, vector));
        Thread B = new Thread (new arrSeguro(obj, vector));

        A.start(); B.start();
        A.join(); B.join();

        System.out.println("Vector tras metodo synchronized: ");
        System.out.println(Arrays.toString(vector));
    }
}
