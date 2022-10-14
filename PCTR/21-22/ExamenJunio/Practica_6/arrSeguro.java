/**
 * arrSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.util.Arrays;

public class arrSeguro extends Thread {
    public static int tam = 10;
    public static int vector[] = new int [tam];
    private Object obj;
    
    public arrSeguro (Object obj){
        this.obj = obj;
    }

    public void run(){
        synchronized(obj){
            for (int i = 0; i < tam; i++)
                vector[i]++;
        }
    }
    public static void main (String[] args) throws Exception {
        Object obj = new Object();
        int tam = 10;

        int vector[] = new int[tam];

        for (int i = 0; i < tam; i++){
            vector[i] = tam;
        }

        System.out.println("Vector inicializado: ");
        System.out.println(Arrays.toString(vector));

        Thread A = new Thread (new arrSeguro(obj));
        Thread B = new Thread (new arrSeguro(obj));

        A.start(); B.start();
        A.join(); B.join();

        System.out.println("Vector tras metodo synchronized: ");
        System.out.println(Arrays.toString(vector));
    }
}
