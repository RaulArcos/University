/**
 * usamonitorImpresion.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 4/12/2021
 */

import java.lang.Exception;

public class UsamonitorImpresion extends Thread{
    public int tipoHebra;
    public monitorImpresion MI;
    public static int impresoras = 3;

    public UsamonitorImpresion (int tH, monitorImpresion MI) {
        this.tipoHebra = tH;
        this.MI = MI;
    }

    public void run (){
        switch (tipoHebra){
            case 0:
                MI.take_print();
            break;
            case 1:
                MI.drop_print(MI.take_print());
            break;
        }
    }
    
    public static void main (String[] args) throws Exception{
        boolean libre[] = new boolean[impresoras];

        for (int i = 0; i < impresoras; i++)
        	libre[i] = true;

        
        monitorImpresion MI = new monitorImpresion(3, libre);

        Thread h1 = new Thread (new UsamonitorImpresion(0, MI));
        Thread h2 = new Thread (new UsamonitorImpresion(1, MI));

        h1.start(); h2.start();
        h1.join(); h2.join();
    }
}