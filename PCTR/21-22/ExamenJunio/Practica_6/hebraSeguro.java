/**
 * hebraSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.util.Scanner;
import java.util.*;

public class hebraSeguro extends Thread {
    private int tipoHilo;
    private static int n =0; // variable de clase
    private int nVueltas;
    private Object obj;

    public hebraSeguro (int nVueltas , int tipoHilo, Object obj) { 
        this.nVueltas = nVueltas; 
        this.tipoHilo = tipoHilo;
        this.obj = obj;
    }

    public void run () {
        synchronized(obj){
            switch (tipoHilo) {
                case 0: 
                    for (int i = 0; i < nVueltas; i ++) 
                        n++; 
                    break ;
                case 1:
                    for (int i = 0; i < nVueltas; i ++) 
                        n--;
                    break ;
            }
        }
    }

    public static int n() {
        return n;
    }

}